cmake_minimum_required(VERSION 3.1.0)
project(server VERSION 0.1.0)


# add_compile_options(-Wall -D_POSIX_C_SOURCE=200809L -lm)

add_executable(clox src/main.c 
    src/common.h 
    src/debug.c src/debug.h
    src/chunk.c src/chunk.h
    src/memory.c src/memory.h
    src/value.c src/value.h
    src/vm.c src/vm.h
    src/scanner.c src/scanner.h
    src/compiler.c src/compiler.h
    src/object.h src/object.c
)
target_include_directories(clox PUBLIC src)
set_property(TARGET clox PROPERTY C_STANDARD 17)
