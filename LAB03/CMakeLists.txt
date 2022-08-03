cmake_minimum_required(VERSION 3.10)
project(LAB03 CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wno-unused-parameter -Wunused)

include(cmake/GTest.cmake)

add_subdirectory(LAB03)

enable_testing()
add_test(tests LAB03/tests)

add_custom_target(tests1
                  COMMAND "./LAB03/tests"
                  DEPENDS tests)