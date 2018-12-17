cmake_minimum_required (VERSION 3.0)
project (ComputuePi)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -O3 ${CMAKE_CXX_FLAGS}")
endif()

add_executable(ComputePi
	main.cpp
	computePi.cpp
	computePi.hpp
    # Add files implementing your thread-safe data structures below
	threadTask.cpp
	threadTask.hpp
	threadQueue.cpp
	threadQueue.hpp
	map.hpp
	map.cpp
	printPi.hpp
	printPi.cpp
)
