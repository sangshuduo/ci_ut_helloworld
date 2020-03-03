cmake_minimum_required(VERSION 3.10)

project(ci_ut_helloworld C)
project(ci_ut_helloworld VERSION 0.1)


SET(CMAKE_C_STANDARD 11)
SET(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(ci_ut_helloworld ci_ut_helloworld.c)

configure_file(ci_ut_helloworld_config.h.in ci_ut_helloworld_config.h)

target_include_directories(ci_ut_helloworld PUBLIC 
    "${PROJECT_BINARY_DIR}"
    )
