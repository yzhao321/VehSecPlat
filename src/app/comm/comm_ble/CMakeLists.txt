project(VehCommBle)

add_library(${PROJECT_NAME} src/comm_ble.c)
add_library(CommBle ALIAS ${PROJECT_NAME})

target_link_libraries(VehCommBle Public)
target_link_libraries(VehCommBle DriverBle)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)