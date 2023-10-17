project(VehCommCan)

add_library(${PROJECT_NAME} src/comm_can.c)
add_library(CommCan ALIAS ${PROJECT_NAME})

target_link_libraries(VehCommCan Public)
target_link_libraries(VehCommCan DriverCan)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)