cmake_minimum_required(VERSION 3.8)
set(TARGET_NAME1 subscriber)
set(TARGET_NAME2 publisher)

add_executable(
        ${TARGET_NAME1}
        ${CMAKE_CURRENT_SOURCE_DIR}/subscriber.cpp
)

add_executable(
        ${TARGET_NAME2}
        ${CMAKE_CURRENT_SOURCE_DIR}/publisher.cpp
)

target_link_libraries(${TARGET_NAME1}
        PRIVATE
        RCF-interface
        RCF
)

target_link_libraries(${TARGET_NAME2}
        PRIVATE
        RCF-interface
        RCF
)
