cmake_minimum_required(VERSION 3.20)
project(LAB02 CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter -Wunused)

include(cmake/GTest.cmake)

add_subdirectory(LAB02)

enable_testing()
add_test(tests LAB02/tests)

add_custom_target(tests1
        COMMAND "./LAB02/tests"
        DEPENDS tests)
