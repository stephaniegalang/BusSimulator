cmake_minimum_required(VERSION 3.10)
project(BusSimulator)
INCLUDE_DIRECTORIES(include)
set(CMAKE_CXX_STANDARD 17)

add_executable(BusSimulator src/main.cpp)