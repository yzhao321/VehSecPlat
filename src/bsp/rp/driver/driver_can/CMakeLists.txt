project(BspCan)

add_library(${PROJECT_NAME} src/driver_can.c)
add_library(DriverCan ALIAS ${PROJECT_NAME})

target_link_libraries(BspCan Public)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)