cmake_minimum_required(VERSION 3.8)
set(TARGET_NAME serverLinkNum)
project(${TARGET_NAME})

add_executable(
        ${TARGET_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(${TARGET_NAME}
        PRIVATE
        RCF-interface
        RCF
)
