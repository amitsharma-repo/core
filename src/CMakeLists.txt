target_sources(lib_core
	#header only
	INTERFACE
	PRIVATE
	../include/RWLock.h
	RWLock.cpp
	)

target_include_directories(lib_core
	PUBLIC
	../include
	)
#target_compile_definitions(lib_core
#	)
set_target_properties(lib_core PROPERTIES
	OUTPUT_NAME core
	)
