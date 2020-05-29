#include <thread>
#include <atomic>
#include <cstdio>

class K{
public:
	static std::atomic< size_t >	num_constructor_calls_;
	static std::atomic< size_t > 	num_destructor_calls_;

	static size_t get_num_constructor_calls() noexcept {return num_constructor_calls_.load(); }
	static size_t get_num_destructor_calls() noexcept {return num_destructor_calls_.load(); }
	static void clear()
	{
		num_constructor_calls_.store( 0 );
		num_destructor_calls_.store( 0 );
	}
};
#if ! USE_GOOGLE_TEST


# ifndef BOOST_TEST_MODULE
	#define BOOST_TEST_MODULE My_Test
#endif
#if ! NOT_DEFINE_MAIN
#	define BOOST_TEST_DYN_LINK		1
	#include <boost/test/unit_test.hpp>
#else
#endif

#define TEST(x,y)	BOOST_AUTO_TEST_CASE( x ## y)
#define EXPECT_TRUE( x )		BOOST_CHECK ( x )
#define EXPECT_FALSE ( x )		BOOST_CHECK (! ( x ) )
#define EXPECT_EQ ( x ,y )		BOOST_CHECK ( ( x ) ==  ( y )  )
#define EXPECT_NE ( x , y )		BOOST_CHECK ( ( x ) != ( y ) )


#else


#include "gtest/gtest.h"

#define BOOST_AUTO_TEST_CASE(x)	TEST( x, x)
#define BOOST_REQUIRE( COND )		EXPECT_TRUE( COND )
#define  BOOST_CHECK( COND )		EXPECT_TRUE( COND )
#define BOOST_CHECK_EQUAL( x, y )	EXPECT_EQ( x, y )
#define BOOST_TEST_MESSAGE( MSG )	EXPECT_TRUE( true ) << MSG

#if ! defined( DONT_DEFINE_MAIN)

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif

#endif
#if 1
#undef EXPECT_EQ
#undef EXPECT_NE
//#undef EXPECT_TRUE
//#undef EXPECT_FALSE

#define EXPECT_EQ( x, y)
#define EXPECT_NE( x, y)
//#define EXPECT_TRUE ( x )
//#define EXPECT_FALSE ( cond )
#endif
