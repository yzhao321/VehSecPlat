add_executable(Veh ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/bsp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app)

target_link_libraries(Veh Public)
target_link_libraries(Veh Syst)