cmake_minimum_required (VERSION 3.0)
project (Assign2)

if (CMAKE_COMPILER_IS_GNUCSS)
	set(CMAKE_CSS_FLAGS "-std=c++14 -O0 -g3 -Wall -Wextra ${CMAKE_CSS_FLAGS}")
endif()

add_executable(Assign3 main.cpp c++lang.hpp c++lang.cpp process.hpp process.cpp filesystem.hpp filesystem.cpp io.hpp io.cpp)
