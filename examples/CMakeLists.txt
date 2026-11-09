cmake_minimum_required(VERSION 3.20)
project(grimace_examples C)

include(Grimace)

add_subdirectory(hello)
add_subdirectory(window)
add_subdirectory(dialog)
add_subdirectory(maths)
add_subdirectory(dll)
add_subdirectory(cxx-basics)
add_subdirectory(window-cxx)
if(GRIMACE_LIBCXX)
    add_subdirectory(stl-text)
    add_subdirectory(stl-collections)
endif()

grimace_package("Grimace Examples" PROVIDER "Grimace"
    TARGETS hello window window-cxx dialog maths greeter greet cxx-basics cxx-counter
    SHORTCUTS hello "Hello" window "Window" window-cxx "Window C++" dialog "Dialog")
