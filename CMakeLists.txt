cmake_minimum_required(VERSION 3.13)
project(core
	LANGUAGES C CXX)
enable_testing()

include(cmake/project_Setting.cmake)
# proejct wide setup
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(Test)

if (NOT DEFINED CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)



set(CMAKE_VERBOSE_MAKEFILE ON)
set(home_root /home/ultimatepandit/Project_SRC/practice_zone/core) 
set(CMAKE_INSTALL_PREFIX ${home_root}/build/install)

option(USE_GOOGLE_TEST "Enable Google tests" OFF)
option(TEST_CORE "Enable core unit tests" OFF)

if(TEST_CORE OR CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	set(TEST_CORE ON CACHE BOOL "Enable core unit tests" FORCE)
	add_subdirectory(tests)
endif()

add_subdirectory(src)
