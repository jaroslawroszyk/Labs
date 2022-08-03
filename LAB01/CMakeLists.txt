cmake_minimum_required(VERSION 3.10)
project(LAB01 CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wno-unused-parameter -Wunused)

include(cmake/GTest.cmake)

add_subdirectory(LAB01)

enable_testing()
add_test(tests LAB01/tests)

add_custom_target(tests1
                  COMMAND "./LAB01/tests"
                  DEPENDS tests)
