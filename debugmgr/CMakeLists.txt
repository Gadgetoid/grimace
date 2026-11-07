cmake_minimum_required(VERSION 3.20)
project(debugmgr C CXX)

include(Grimace)

if(GRIMACE_WIN32_WCE GREATER_EQUAL 300)
    grimace_add_executable(debugmgr main.cpp protocol.cpp server.cpp mailbox.cpp device_ce.cpp)
    target_link_libraries(debugmgr PRIVATE grimace::winsock)
elseif(GRIMACE_ARCH STREQUAL "sh3")
    grimace_add_executable(debugmgr OUTPUT grimace-debugmgr.exe debugmgr.c)
else()
    grimace_add_executable(debugmgr debugmgr.c)
endif()
