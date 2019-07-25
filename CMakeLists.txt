cmake_minimum_required(VERSION 3.10.2)
project(neat-dino=simulation)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(tt ${SOURCES})

