cmake_minimum_required(VERSION 3.8)
set(TARGET_NAME RCF)
project(${TARGET_NAME})

set(SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/RCF/RCF.cpp)

add_library(${TARGET_NAME}-interface INTERFACE)
add_library(
        ${TARGET_NAME}
        STATIC
        ${SRC_FILES}
)

target_include_directories(
        ${TARGET_NAME}-interface
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
        ${TARGET_NAME}
        PUBLIC
        pthread
        dl
        uuid
)
