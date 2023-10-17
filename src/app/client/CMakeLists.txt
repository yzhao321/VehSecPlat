project(VehClient)

add_library(${PROJECT_NAME} src/client.c src/client_cmd.c)
add_library(Client ALIAS ${PROJECT_NAME})

target_link_libraries(VehClient Public)
target_link_libraries(VehClient ServiceDosBasic)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)