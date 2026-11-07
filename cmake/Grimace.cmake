include_guard(GLOBAL)

get_filename_component(GRIMACE_TOOLCHAIN_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
find_package(Python3 REQUIRED COMPONENTS Interpreter)
enable_language(C)
enable_language(ASM)
enable_language(CXX)

set(GRIMACE_IMPORTS_DIR "${CMAKE_BINARY_DIR}/grimace/imports")
file(GLOB GRIMACE_MANIFEST_FILES "${GRIMACE_TOOLCHAIN_ROOT}/exports/*/*")
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${GRIMACE_MANIFEST_FILES} "${GRIMACE_TOOLCHAIN_ROOT}/tools/manifests.py")
execute_process(
    COMMAND "${Python3_EXECUTABLE}" "${GRIMACE_TOOLCHAIN_ROOT}/tools/manifests.py" --arch "${GRIMACE_ARCH}" --version "${GRIMACE_CE_VERSION}"
            --platform "${GRIMACE_PLATFORM}" --device "${GRIMACE_DEVICE}" --output "${GRIMACE_IMPORTS_DIR}"
    OUTPUT_VARIABLE GRIMACE_IMPORTS_SUMMARY OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_VARIABLE GRIMACE_IMPORTS_ERROR ERROR_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE GRIMACE_IMPORTS_RESULT)
if(NOT GRIMACE_IMPORTS_RESULT EQUAL 0)
    message(FATAL_ERROR "${GRIMACE_IMPORTS_ERROR}")
endif()
message(STATUS "${GRIMACE_IMPORTS_SUMMARY}")

if(NOT DEFINED GRIMACE_OS_SYMBOLS)
    if(GRIMACE_ARCH STREQUAL "sh3")
        set(GRIMACE_OS_SYMBOLS "$ENV{GRIMACE_SH3_OS_SYMBOLS}")
    else()
        set(GRIMACE_OS_SYMBOLS "$ENV{GRIMACE_OS_SYMBOLS}")
    endif()
endif()
if(GRIMACE_OS_SYMBOLS)
    get_filename_component(GRIMACE_OS_SYMBOLS "${GRIMACE_OS_SYMBOLS}" ABSOLUTE)
    if(NOT EXISTS "${GRIMACE_OS_SYMBOLS}/nk.elf" OR NOT EXISTS "${GRIMACE_OS_SYMBOLS}/rom.elf")
        message(WARNING "GRIMACE_OS_SYMBOLS is ${GRIMACE_OS_SYMBOLS}, which lacks nk.elf or rom.elf")
    endif()
endif()

add_library(grimace_headers INTERFACE)
if(GRIMACE_LIBCXX)
    target_include_directories(grimace_headers SYSTEM INTERFACE "$<$<COMPILE_LANGUAGE:CXX>:${GRIMACE_TOOLCHAIN_ROOT}/include/grimace/libcxx>"
                               "$<$<COMPILE_LANGUAGE:CXX>:${GRIMACE_LLVM_ROOT}/include/c++/v1>")
endif()
target_include_directories(grimace_headers SYSTEM INTERFACE "${GRIMACE_TOOLCHAIN_ROOT}/include" "${GRIMACE_TOOLCHAIN_ROOT}/include/w32api")
add_library(grimace::headers ALIAS grimace_headers)

file(GLOB_RECURSE GRIMACE_LIBC_FILES "${GRIMACE_TOOLCHAIN_ROOT}/runtime/libc/*")
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${GRIMACE_LIBC_FILES} "${GRIMACE_TOOLCHAIN_ROOT}/tools/runtime.py")
execute_process(
    COMMAND "${Python3_EXECUTABLE}" "${GRIMACE_TOOLCHAIN_ROOT}/tools/runtime.py" --arch "${GRIMACE_ARCH}" --imports "${GRIMACE_IMPORTS_DIR}"
            --output "${GRIMACE_IMPORTS_DIR}/libc-sources"
    RESULT_VARIABLE GRIMACE_LIBC_RESULT)
if(NOT GRIMACE_LIBC_RESULT EQUAL 0)
    message(FATAL_ERROR "tools/runtime.py failed")
endif()
file(STRINGS "${GRIMACE_IMPORTS_DIR}/libc-sources" GRIMACE_LIBC_SOURCES)
file(GLOB GRIMACE_RUNTIME_SOURCES "${GRIMACE_TOOLCHAIN_ROOT}/runtime/c99/*.c")
file(GLOB GRIMACE_COMPILER_RT_SOURCES "${GRIMACE_TOOLCHAIN_ROOT}/runtime/compiler-rt/*.c")
file(GLOB GRIMACE_COMMON_RUNTIME_SOURCES "${GRIMACE_TOOLCHAIN_ROOT}/runtime/*.c")
list(APPEND GRIMACE_RUNTIME_SOURCES ${GRIMACE_LIBC_SOURCES} ${GRIMACE_COMPILER_RT_SOURCES} ${GRIMACE_COMMON_RUNTIME_SOURCES})
add_library(grimace_runtime STATIC EXCLUDE_FROM_ALL ${GRIMACE_RUNTIME_SOURCES})
target_include_directories(grimace_runtime PRIVATE "${GRIMACE_TOOLCHAIN_ROOT}/include")
target_compile_options(grimace_runtime PRIVATE -fno-builtin -w)
add_library(grimace::runtime ALIAS grimace_runtime)

file(GLOB GRIMACE_CXX_RUNTIME_SOURCES "${GRIMACE_TOOLCHAIN_ROOT}/runtime/cxx/*.cpp")
add_library(grimace_cxx_runtime STATIC EXCLUDE_FROM_ALL ${GRIMACE_CXX_RUNTIME_SOURCES})
target_link_libraries(grimace_cxx_runtime PRIVATE grimace_headers)
add_library(grimace::cxx_runtime ALIAS grimace_cxx_runtime)

if(GRIMACE_LIBCXX)
    set(GRIMACE_LIBCXX_SOURCE "${GRIMACE_LLVM_ROOT}/share/libcxx/src")
    file(GLOB GRIMACE_CXX_STDLIB_SOURCES "${GRIMACE_TOOLCHAIN_ROOT}/runtime/libcxx/*.cpp")
    foreach(source algorithm functional hash memory string vector)
        list(APPEND GRIMACE_CXX_STDLIB_SOURCES "${GRIMACE_LIBCXX_SOURCE}/${source}.cpp")
    endforeach()
    add_library(grimace_cxx_stdlib STATIC EXCLUDE_FROM_ALL ${GRIMACE_CXX_STDLIB_SOURCES})
    target_link_libraries(grimace_cxx_stdlib PRIVATE grimace_headers)
    target_include_directories(grimace_cxx_stdlib PRIVATE "${GRIMACE_LIBCXX_SOURCE}")
    target_compile_definitions(grimace_cxx_stdlib PRIVATE _LIBCPP_BUILDING_LIBRARY)
    target_compile_options(grimace_cxx_stdlib PRIVATE -std=c++23 -w)
    set_source_files_properties("${GRIMACE_LIBCXX_SOURCE}/string.cpp" PROPERTIES COMPILE_DEFINITIONS GRIMACE_C99_SWPRINTF)
    add_library(grimace::cxx_stdlib ALIAS grimace_cxx_stdlib)
    set(GRIMACE_CXX_LIBRARIES grimace::cxx_stdlib grimace::cxx_runtime)
else()
    set(GRIMACE_CXX_LIBRARIES grimace::cxx_runtime)
endif()

file(GLOB GRIMACE_EXPORT_LISTS "${GRIMACE_IMPORTS_DIR}/*.txt")
foreach(exports IN LISTS GRIMACE_EXPORT_LISTS)
    get_filename_component(dll "${exports}" NAME_WE)
    string(TOUPPER "${dll}" dll_upper)
    set(lazy "${GRIMACE_IMPORTS_DIR}/${dll}.lazy")
    set(stubs "${GRIMACE_IMPORTS_DIR}/${dll}.S")
    add_custom_command(
        OUTPUT "${stubs}"
        COMMAND "${Python3_EXECUTABLE}" "${GRIMACE_TOOLCHAIN_ROOT}/tools/mkimplib.py" "${exports}" "${dll_upper}.dll" "${stubs}" --arch ${GRIMACE_ARCH}
                --lazy "${lazy}"
        DEPENDS "${exports}" "${lazy}" "${GRIMACE_TOOLCHAIN_ROOT}/tools/mkimplib.py"
        VERBATIM)
    add_library(grimace_${dll} STATIC EXCLUDE_FROM_ALL "${stubs}")
    add_library(grimace::${dll} ALIAS grimace_${dll})
endforeach()

function(_grimace_link target script cxx_entry)
    set_target_properties(${target} PROPERTIES SUFFIX ".elf" LINK_DEPENDS "${script}")
    target_link_options(${target} PRIVATE -T "${script}" "$<$<LINK_LANGUAGE:CXX>:--entry=${cxx_entry}>")
    target_link_libraries(${target} PRIVATE grimace::headers grimace::runtime grimace::coredll "$<$<LINK_LANGUAGE:CXX>:${GRIMACE_CXX_LIBRARIES}>")
endfunction()

function(_grimace_pe target output)
    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS "${GRIMACE_TOOLCHAIN_ROOT}/tools/mkpe.py")
    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND "${Python3_EXECUTABLE}" "${GRIMACE_TOOLCHAIN_ROOT}/tools/mkpe.py" "$<TARGET_FILE:${target}>" "$<TARGET_FILE_DIR:${target}>/${output}" "--ce-version=${GRIMACE_CE_VERSION}" ${ARGN}
        VERBATIM)
endfunction()

function(_grimace_resources target out_options)
    set(options "")
    set(dependencies "")
    set(scripts "")
    foreach(resource IN LISTS ARGN)
        get_filename_component(resource "${resource}" ABSOLUTE)
        if(resource MATCHES "\\.rc$")
            list(APPEND scripts "${resource}")
        else()
            list(APPEND dependencies "${resource}")
        endif()
    endforeach()
    if(scripts)
        find_program(GRIMACE_RC llvm-rc HINTS "${GRIMACE_LLVM_ROOT}/bin" REQUIRED)
    endif()
    set(GRIMACE_RC_ARCH_DEFINES "")
    foreach(define IN LISTS GRIMACE_ARCH_DEFINES)
        list(APPEND GRIMACE_RC_ARCH_DEFINES -D "${define}")
    endforeach()
    set(rc_includes "")
    foreach(directory IN LISTS GRIMACE_RC_INCLUDES)
        list(APPEND rc_includes -I "${directory}")
    endforeach()
    foreach(script IN LISTS scripts)
        get_filename_component(name "${script}" NAME_WE)
        get_filename_component(directory "${script}" DIRECTORY)
        set(compiled "${CMAKE_CURRENT_BINARY_DIR}/${target}_${name}.res")
        add_custom_command(
            OUTPUT "${compiled}"
            COMMAND "${GRIMACE_RC}" -D "_WIN32_WCE=${GRIMACE_WIN32_WCE}" ${GRIMACE_RC_ARCH_DEFINES} -I "${GRIMACE_TOOLCHAIN_ROOT}/include" -I "${GRIMACE_TOOLCHAIN_ROOT}/include/w32api" -I "${directory}" ${rc_includes} -FO "${compiled}" -- "${script}"
            DEPENDS "${script}" ${dependencies}
            VERBATIM)
        target_sources(${target} PRIVATE "${compiled}")
        set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS "${compiled}")
        list(APPEND options "--resources=${compiled}")
    endforeach()
    set(${out_options} ${options} PARENT_SCOPE)
endfunction()

function(_grimace_gdb_scripts)
    get_property(executables GLOBAL PROPERTY GRIMACE_EXECUTABLES)
    get_property(libraries GLOBAL PROPERTY GRIMACE_LIBRARIES)
    set(library_folders "")
    set(library_uploads "")
    foreach(library IN LISTS libraries)
        get_target_property(output ${library} GRIMACE_OUTPUT)
        string(APPEND library_folders ":$<TARGET_FILE_DIR:${library}>")
        string(APPEND library_uploads "  remote put \"$<TARGET_FILE_DIR:${library}>/${output}\" /Windows/${output}\n")
    endforeach()
    set(os_symbols_setup "")
    set(os_symbols_folder "")
    set(os_symbols_load "")
    if(GRIMACE_OS_SYMBOLS)
        set(os_symbols_setup "add-symbol-file \"${GRIMACE_OS_SYMBOLS}/nk.elf\"
python
import os
def grimace_os_symbols(event):
    folder = os.path.realpath(\"${GRIMACE_OS_SYMBOLS}\")
    loaded = [os.path.realpath(objfile.filename) for objfile in gdb.objfiles() if objfile.filename]
    if os.path.join(folder, \"rom.elf\") in loaded:
        return
    files = {name.lower(): name for name in os.listdir(folder)}
    for line in gdb.execute(\"info sharedlibrary\", to_string=True).splitlines():
        fields = line.split()
        if len(fields) < 2 or fields[-2] != \"No\":
            continue
        name = files.get(os.path.basename(fields[-1]).lower())
        if name and os.path.join(folder, name) not in loaded:
            gdb.execute(\"add-symbol-file \\\"%s\\\"\" % os.path.join(folder, name))
            loaded.append(os.path.join(folder, name))
    if [path for path in loaded if os.path.dirname(path) == folder and os.path.basename(path) != \"nk.elf\"]:
        return
    gdb.execute(\"remove-symbol-file \\\"%s\\\"\" % os.path.join(folder, \"nk.elf\"))
    gdb.execute(\"add-symbol-file \\\"%s\\\"\" % os.path.join(folder, \"rom.elf\"))
gdb.events.stop.connect(grimace_os_symbols)
end
")
        set(os_symbols_folder ":${GRIMACE_OS_SYMBOLS}")
        set(os_symbols_load "  sharedlibrary\n")
    endif()
    set(architecture "")
    if(GRIMACE_ARCH STREQUAL "sh3")
        set(architecture "set architecture sh3\n")
    elseif(GRIMACE_ARCH STREQUAL "arm")
        set(architecture "set architecture armv4\n")
    endif()
    foreach(target IN LISTS executables)
        get_target_property(output ${target} GRIMACE_OUTPUT)
        file(GENERATE OUTPUT "$<TARGET_FILE:${target}>.gdb" CONTENT
"${architecture}set confirm off
set exec-file-mismatch off
maint set target-non-stop on
file \"$<TARGET_FILE:${target}>\"
${os_symbols_setup}set breakpoint pending on
set solib-search-path $<TARGET_FILE_DIR:${target}>${library_folders}${os_symbols_folder}
set remote exec-file /Windows/${output}
define grimace-load
  remote put \"$<TARGET_FILE_DIR:${target}>/${output}\" /Windows/${output}
${library_uploads}${os_symbols_load}end
")
    endforeach()
endfunction()

function(_grimace_add_gdb_script target output kind)
    set_target_properties(${target} PROPERTIES GRIMACE_OUTPUT "${output}")
    set_property(GLOBAL APPEND PROPERTY ${kind} ${target})
    get_property(deferred GLOBAL PROPERTY GRIMACE_GDB_SCRIPTS_DEFERRED)
    if(NOT deferred)
        set_property(GLOBAL PROPERTY GRIMACE_GDB_SCRIPTS_DEFERRED TRUE)
        cmake_language(DEFER DIRECTORY "${CMAKE_SOURCE_DIR}" CALL _grimace_gdb_scripts)
    endif()
endfunction()

function(_grimace_require_exports target)
    foreach(export IN LISTS ARGN)
        string(REGEX REPLACE "^[^=]*=" "" symbol "${export}")
        target_link_options(${target} PRIVATE "--undefined=${symbol}")
    endforeach()
endfunction()

function(grimace_add_executable target)
    cmake_parse_arguments(PARSE_ARGV 1 GRIMACE "EXCLUDE_FROM_ALL" "OUTPUT;ICON" "RESOURCES")
    if(NOT GRIMACE_OUTPUT)
        set(GRIMACE_OUTPUT "${target}.exe")
    endif()
    set(exclude "")
    if(GRIMACE_EXCLUDE_FROM_ALL)
        set(exclude EXCLUDE_FROM_ALL)
    endif()
    add_executable(${target} ${exclude} ${GRIMACE_UNPARSED_ARGUMENTS})
    _grimace_link(${target} "${GRIMACE_TOOLCHAIN_ROOT}/ld/exe.ld" __grimace_exe_start)
    set(options "")
    if(GRIMACE_ICON)
        get_filename_component(icon "${GRIMACE_ICON}" ABSOLUTE)
        set(options "--icon=${icon}")
    endif()
    _grimace_resources(${target} resource_options ${GRIMACE_RESOURCES})
    _grimace_pe(${target} "${GRIMACE_OUTPUT}" ${options} ${resource_options})
    _grimace_add_gdb_script(${target} "${GRIMACE_OUTPUT}" GRIMACE_EXECUTABLES)
endfunction()

function(grimace_add_library target)
    cmake_parse_arguments(PARSE_ARGV 1 GRIMACE "EXCLUDE_FROM_ALL" "OUTPUT;EXPORTS_FILE" "EXPORTS;RESOURCES")
    if(NOT GRIMACE_OUTPUT)
        set(GRIMACE_OUTPUT "${target}.dll")
    endif()
    if(NOT GRIMACE_EXPORTS AND NOT GRIMACE_EXPORTS_FILE)
        message(FATAL_ERROR "grimace_add_library(${target}) needs EXPORTS or EXPORTS_FILE")
    endif()
    set(exclude "")
    if(GRIMACE_EXCLUDE_FROM_ALL)
        set(exclude EXCLUDE_FROM_ALL)
    endif()
    add_executable(${target} ${exclude} ${GRIMACE_UNPARSED_ARGUMENTS})
    _grimace_link(${target} "${GRIMACE_TOOLCHAIN_ROOT}/ld/dll.ld" __grimace_dll_start)
    set(options "")
    _grimace_require_exports(${target} ${GRIMACE_EXPORTS})
    if(GRIMACE_EXPORTS)
        string(JOIN "," exports ${GRIMACE_EXPORTS})
        list(APPEND options "--exports=${exports}")
    endif()
    if(GRIMACE_EXPORTS_FILE)
        get_filename_component(exports_file "${GRIMACE_EXPORTS_FILE}" ABSOLUTE)
        file(STRINGS "${exports_file}" file_exports)
        _grimace_require_exports(${target} ${file_exports})
        list(APPEND options "--exports-file=${exports_file}")
        set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS "${exports_file}")
    endif()
    _grimace_resources(${target} resource_options ${GRIMACE_RESOURCES})
    _grimace_pe(${target} "${GRIMACE_OUTPUT}" ${options} ${resource_options})
    if(NOT GRIMACE_EXCLUDE_FROM_ALL)
        _grimace_add_gdb_script(${target} "${GRIMACE_OUTPUT}" GRIMACE_LIBRARIES)
    endif()
endfunction()
