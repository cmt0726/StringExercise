cmake_minimum_required(VERSION 3.10)

project(prog LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CUSTOM_CXX_OPTIONS -std=c++14)
set(CUSTOM_C_OPTIONS -std=c11)

add_compile_options(
    -g
    -O0
    "$<$<COMPILE_LANGUAGE:C>:${CUSTOM_C_OPTIONS}>"
    "$<$<COMPILE_LANGUAGE:CXX>:${CUSTOM_CXX_OPTIONS}>"
    -Werror
    -Wextra
    -Wall
    -Wshadow
    -Wno-unused-parameter
)

file(GLOB SOURCES *.cpp )

add_executable(prog  ${SOURCES})
