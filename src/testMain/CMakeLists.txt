if(NOT USE_GOOGLE_TEST)
	find_package(Boost REQUIRED COMPONENTS unit_test_framework system)
endif()

target_sources(framework_test
	PRIVATE
	TestMain.cpp
	)
target_compile_definitions(framework_test
	PUBLIC
	$<$<BOOL:${USE_GOOLGE_TEST}>:USE_GOOGLE_TEST>
	)

target_include_directories(framework_test
	PUBLIC
	$<$<NOT:$<BOOL:${USE_GOOGLE_TEST}>>:$<BUILD_INTERFACE:${Boost_INCLUE_DIRS}>>
	$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/common/include>
	)

target_link_libraries(framework_test
	PUBLIC
	$<$<BOOL:${USE_GOOGLE_TEST}>:gtest>
	$<$<NOT:$<BOOL:${USE_GOOGLE_TEST}>>:Boost::unit_test_framework>
	$<$<NOT:$<BOOL:${USE_GOOGLE_TEST}>>::Boost:system>
	)

set_target_properties(framework_test PROPERTIES
	OUTPUT_NAME test
	)
add_library(core::framework_test ALIAS framework_test)
