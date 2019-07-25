cmake_minimum_required(VERSION 3.10.2)
project(neat-dino-simulation C CXX)

include_directories(include)
include_directories(src)

file(GLOB SOURCES "src/*.cpp")

add_executable(tt "${SOURCES}")
set_target_properties(tt PROPERTIES LINKER_LANGUAGE CXX)

