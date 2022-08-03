add_library(implementations src/Palindrom.cpp src/Dec2Any.cpp src/Any2Dec.cpp src/Boyera.cpp)
target_include_directories(implementations PUBLIC include)

add_executable(tests uts/Palindrom_tests.cpp uts/Dec2Any_tests.cpp uts/Any2Dec_tests.cpp uts/Boyera_tests.cpp)
target_link_libraries(tests gmock_main gtest gmock implementations)
