if(USE_GOOGLE_TEST)
	include(GoogleTest)
endif()

set(CMAKE_THREAD_PREFER_PTHREAD YES)
set(THREADS_PREFER_PTHREAD_FLAG YES)
find_package(Threads REQUIRED)

add_executable(test_RWLock test_RWLock.cpp)
target_include_directories(test_RWLock
    PUBLIC
    ../include
    )   
add_tests(test_RWLock LABELS "core")
target_link_libraries(test_RWLock
	PRIVATE
	framework_test
    core	
	Threads::Threads
)

