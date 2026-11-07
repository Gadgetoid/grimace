cmake_minimum_required(VERSION 3.20)
project(lazy C)

include(Grimace)

grimace_add_executable(lazy lazy.c ICON lazy.ico)
