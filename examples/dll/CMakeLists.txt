grimace_add_library(greet greet.c EXPORTS Add Greeting)
grimace_add_executable(greeter greeter.c)
add_dependencies(greeter greet)
