cmake_minimum_required(VERSION 3.10)

project(test_callback CXX)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    test_callback.cpp
)

target_link_libraries(${PROJECT_NAME} 
    GTest::gtest 
    GTest::gtest_main
)

add_test(all_tests ${PROJECT_NAME})
