cmake_minimum_required (VERSION 3.0)
project (Assn7)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -O3 ${CMAKE_CXX_FLAGS}")
endif()

add_executable(Assn7
	main.cpp
	tuple.cpp
	tuple.hpp
)
