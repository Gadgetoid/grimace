cmake_minimum_required(VERSION 3.20)
project(grimace_examples_matrix NONE)

include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/GrimaceMatrix.cmake)

grimace_matrix(NAME "Grimace Examples" SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/.. PACKAGE
    TARGETS mips-ce1 mips-ce2 sh3-ce1 sh3-ce101 sh3-ce2 x86-ce2 arm-ce3)
