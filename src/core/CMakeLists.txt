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
install(TARGETS core
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )   
#target_compile_definitions(core
#	)
set_target_properties(core PROPERTIES
	OUTPUT_NAME core
	)
