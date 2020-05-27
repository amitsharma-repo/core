
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
#define EXPECT_FALSE (x )		BOOST_CHECK (! ( x ) )
#define EXPECT_EQ (x ,y )		BOOST_CECK( ( x ) == ( y ) )
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
