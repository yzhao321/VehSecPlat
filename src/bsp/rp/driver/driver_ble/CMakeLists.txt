project(BspBle)

add_library(${PROJECT_NAME} src/driver_ble.c)
add_library(DriverBle ALIAS ${PROJECT_NAME})

target_link_libraries(BspBle Public)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)