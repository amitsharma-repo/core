target_sources(core
	#header only
	INTERFACE
	PRIVATE
	../../include/core/RWLock.h
	RWLock.cpp
	)

target_include_directories(core
	PUBLIC
	../../include/core
	)
#target_compile_definitions(core
#	)
set_target_properties(core PROPERTIES
	OUTPUT_NAME core
	)
