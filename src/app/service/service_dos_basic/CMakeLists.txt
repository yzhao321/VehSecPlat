project(VehServiceDosBasic)

add_library(${PROJECT_NAME} src/service_dos_basic.c)
add_library(ServiceDosBasic ALIAS ${PROJECT_NAME})

target_link_libraries(VehServiceDosBasic Public)
target_link_libraries(VehServiceDosBasic CommBle)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)