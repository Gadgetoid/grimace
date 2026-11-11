cmake_minimum_required(VERSION 3.20)
project(ce6 C)

include(Grimace)

grimace_add_executable(program program.c)
grimace_add_executable(program_high program.c OUTPUT program-high.exe TEXT_ADDRESS 0x00801000)
grimace_add_library(applet applet.c OUTPUT applet.cpl RESOURCES applet.rc applet.ico EXPORTS CPlApplet)
grimace_add_library(driver driver.c OUTPUT driver.dll EXPORTS_FILE driver.exports)
target_link_libraries(driver PRIVATE grimace::ceddk)
