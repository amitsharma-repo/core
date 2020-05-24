cmake_minimum_required(VERSION 3.13)
project(core
	LANGUAGES C CXX)
include(cmake/project_Setting.cmake)

if (NOT DEFINED CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)



set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(home_root /home/ultimatepandit/Project_SRC/practice_zone/core) 
set(CMAKE_INSTALL_PREFIX ${home_root}/build/install)
add_library(lib_core)
add_subdirectory(src)
