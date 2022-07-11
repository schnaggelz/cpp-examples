cmake_minimum_required(VERSION 3.10)

option(ENABLE_TESTING "Turn on to enable tests" ON)

project(observer CXX)

set(HEADER_FILES
    include/observer/dispatcher.hpp
    include/observer/event.hpp
    include/observer/observer.hpp
)

add_library(${PROJECT_NAME} STATIC
    ${HEADER_FILES}
    src/observer.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${HEADER_FILES})

add_library(examples::observer ALIAS ${PROJECT_NAME})
    
if (ENABLE_TESTING)                           
    enable_testing()
    add_subdirectory(test)
endif()

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

