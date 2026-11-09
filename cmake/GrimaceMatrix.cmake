include_guard(GLOBAL)
include(ExternalProject)

get_filename_component(GRIMACE_TOOLCHAIN_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

foreach(arch MIPS SH3 X86 ARM)
    set(GRIMACE_${arch}_LLVM "$ENV{GRIMACE_${arch}_LLVM}" CACHE PATH "LLVM for the ${arch} targets, empty for the toolchain's default")
endforeach()

function(grimace_matrix)
    cmake_parse_arguments(PARSE_ARGV 0 MATRIX "PACKAGE" "SOURCE_DIR;NAME" "TARGETS;CMAKE_ARGS")
    if(NOT MATRIX_SOURCE_DIR)
        message(FATAL_ERROR "grimace_matrix needs SOURCE_DIR")
    endif()
    get_filename_component(MATRIX_SOURCE_DIR "${MATRIX_SOURCE_DIR}" ABSOLUTE)
    set(builds "")
    set(package_folders "")
    foreach(target IN LISTS MATRIX_TARGETS)
        if(NOT target MATCHES "^(mips|sh3|x86|arm)-ce(1|101|2|3)(-([A-Za-z0-9_]+))?$")
            message(FATAL_ERROR "grimace_matrix: ${target} isn't <arch>-ce<version>[-<device>], e.g. mips-ce1, sh3-ce101 or arm-ce3-jornada720")
        endif()
        set(arch "${CMAKE_MATCH_1}")
        set(version "${CMAKE_MATCH_2}")
        set(device "${CMAKE_MATCH_4}")
        if(version STREQUAL "101")
            set(version "1.01")
        endif()
        string(TOUPPER "${arch}" arch_upper)
        set(llvm "")
        if(GRIMACE_${arch_upper}_LLVM)
            set(llvm "-DGRIMACE_LLVM_ROOT=${GRIMACE_${arch_upper}_LLVM}")
        endif()
        set(build_command "${CMAKE_COMMAND}" --build <BINARY_DIR>)
        if(MATRIX_PACKAGE)
            list(APPEND build_command COMMAND "${CMAKE_COMMAND}" --build <BINARY_DIR> --target packages)
        endif()
        string(MAKE_C_IDENTIFIER "grimace_${target}" build)
        ExternalProject_Add(${build}
            SOURCE_DIR "${MATRIX_SOURCE_DIR}"
            BINARY_DIR "${CMAKE_BINARY_DIR}/${target}"
            CMAKE_ARGS "-DCMAKE_TOOLCHAIN_FILE=${GRIMACE_TOOLCHAIN_ROOT}/cmake/toolchain.cmake" "-DGRIMACE_ARCH=${arch}"
                       "-DGRIMACE_CE_VERSION=${version}" "-DGRIMACE_DEVICE=${device}" ${llvm} ${MATRIX_CMAKE_ARGS}
            BUILD_COMMAND ${build_command}
            INSTALL_COMMAND ""
            BUILD_ALWAYS ON)
        list(APPEND builds ${build})
        list(APPEND package_folders "${CMAKE_BINARY_DIR}/${target}/packages")
    endforeach()
    if(MATRIX_PACKAGE)
        set(name_option "")
        if(MATRIX_NAME)
            set(name_option --name "${MATRIX_NAME}")
        endif()
        add_custom_target(packages ALL
            COMMAND "${Python3_EXECUTABLE}" "${GRIMACE_TOOLCHAIN_ROOT}/tools/mkpackage.py" --collect ${package_folders}
                    --output "${CMAKE_BINARY_DIR}/packages" ${name_option}
            DEPENDS ${builds}
            VERBATIM)
    endif()
endfunction()
