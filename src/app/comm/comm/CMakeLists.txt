project(VehComm)

add_library(${PROJECT_NAME} src/comm.c)
add_library(Comm ALIAS ${PROJECT_NAME})

target_link_libraries(VehComm Public)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)