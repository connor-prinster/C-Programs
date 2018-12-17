cmake_minimum_required (VERSION 3.0)
project (Assign4)

if(CMAKE_COMPILER_IS_GNUCSS)
	SET(CMAKE_CSS_FLAGS "-std=c++14 -O0 -g3 -Wall -Wextra ${CMAKE_CSS_FLAGS}")
endif()

add_executable(Assign4 main.cpp)
