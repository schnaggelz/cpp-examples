cmake_minimum_required(VERSION 3.10)

project(test_callback CXX)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    callable_test.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        examples::callback
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE
        GTest::gtest 
        GTest::gtest_main
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

add_test(all_tests ${PROJECT_NAME})
