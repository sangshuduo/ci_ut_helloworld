cmake_minimum_required(VERSION 3.10)

project(ci_ut_helloworld C)
project(ci_ut_helloworld VERSION 0.1)

SET(CMAKE_C_STANDARD 11)
SET(CMAKE_VERBOSE_MAKEFILE ON)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_executable(ci_ut_helloworld ci_ut_helloworld.c)

configure_file(ci_ut_helloworld_config.h.in ci_ut_helloworld_config.h)

target_include_directories(ci_ut_helloworld PUBLIC 
    "${PROJECT_BINARY_DIR}"
    )

if (${COVER} MATCHES "true")
  SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
  SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov --coverage")
  set_target_properties(ci_ut_helloworld PROPERTIES COMPILE_FLAGS ${GCC_COVERAGE_COMPILE_FLAGS} )
  set_target_properties(ci_ut_helloworld PROPERTIES LINK_FLAGS ${GCC_COVERAGE_LINK_FLAGS} )
endif()
