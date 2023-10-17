cmake_minimum_required(VERSION 3.15)
project(Veh)

set(CMAKE_C_STANDARD 99)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
