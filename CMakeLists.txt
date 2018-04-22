cmake_minimum_required(VERSION 3.10)
project(BusSimulator)
INCLUDE_DIRECTORIES(include)
set(CMAKE_CXX_STANDARD 17)

add_executable(BusSimulator main.cpp Town.cpp Passenger.cpp include/Algorithm.h include/Town.h include/Passenger.h include/Edge.h include/Bus.h include/Algorithm.h include/EdgeMap.h)
