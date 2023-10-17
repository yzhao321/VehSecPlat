project(VehSyst)

add_library(${PROJECT_NAME} src/syst.c)
add_library(Syst ALIAS ${PROJECT_NAME})

target_link_libraries(VehSyst Public)
target_link_libraries(VehSyst Comm)
target_link_libraries(VehSyst Service)
target_link_libraries(VehSyst Client)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)