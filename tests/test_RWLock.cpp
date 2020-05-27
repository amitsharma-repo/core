#include <RWLock.h>
#include <iostream>

struct Test
{
	static void test_multiple_Read_one_Write() {
		std::cout << "test case one read one write" <<std::endl;
	}
};
