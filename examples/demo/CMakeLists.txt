cmake_minimum_required(VERSION 3.8)
set(TARGET_NAME1 server)
set(TARGET_NAME2 client)

add_executable(
        ${TARGET_NAME1}
        ${CMAKE_CURRENT_SOURCE_DIR}/ex1_server.cpp
)

add_executable(
        ${TARGET_NAME2}
        ${CMAKE_CURRENT_SOURCE_DIR}/ex1_client.cpp
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
