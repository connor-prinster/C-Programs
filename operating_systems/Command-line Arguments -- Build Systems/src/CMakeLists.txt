cmake_minimum_required (VERSION 3.0)
project (Assign2)

if (CMAKE_COMPILER_IS_GNUCSS)
	set(CMALE_CSS_FLAGS "-std=c++14 ${CMAKE_CSS_FLAGS}")
endif()

add_executable(Assign2 main.cpp compute-pi.cpp compute-pi.hpp compute-fib.cpp compute-fib.hpp compute-e.cpp compute-e.hpp)
