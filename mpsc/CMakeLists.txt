cmake_minimum_required(VERSION 3.10)

option(ENABLE_TESTING "Turn on to enable tests" ON)

project(mpsc CXX)

set(HEADER_FILES
    include/mpsc/ring.hpp
)

add_library(${PROJECT_NAME} STATIC
    ${HEADER_FILES}
    src/ring.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        examples::callback
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${HEADER_FILES})

add_library(examples::mpsc ALIAS ${PROJECT_NAME})
    
if (ENABLE_TESTING)                           
    enable_testing()
    add_subdirectory(test)
endif()

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

