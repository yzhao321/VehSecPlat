project(VehPublic)

add_library(${PROJECT_NAME} src/public.c)
add_library(Public ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)