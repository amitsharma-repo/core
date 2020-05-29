#include <TestMain.cpp>
#include <RWLock.h>
#include <thread>

#include <iostream>
using namespace core;
void global_read(int nCpy_1, int nCpy_2)
{
	//EXPECT_EQ(nCpy_1, nCpy_2);
}
void global_write(int nCpy_1, int nCpy_2, int diff)
{
	//EXPECT_EQ(nCpy_1, nCpy_2 - diff);
}

TEST(RWLock, owned_creation )
{
	RWLock rw_lock;
	int nShared_res = 0;
	BOOST_CHECK( nShared_res == 0);
	//EXPECT_EQ(0,nShared_res);
	/*int nRead_thread_Cnt = 0;
	while(nRead_thread_Cnt++ < 100)
	{
		std::thread read_thread([&]()
		{
			rw_lock.read_lock();
		    int nCpy = nShared_res;
		    sleep(1000);
   			global_read(nCpy, nShared_res);
		    rw_lock.read_unlock();
	
		});
	}
	int nWrite_thread_Cnt = 0;
	while(nWrite_thread_Cnt++ < 100)
	{
		std::thread write_thread([&]()
		{
			rw_lock.write_lock();
	   		int nCpy = nShared_res;
	   		int nDiff = rand();
            nShared_res += nDiff;
		    sleep(1000);
		    global_write(nCpy, nShared_res, nDiff);
		    rw_lock.write_unlock();
		});
	}*/
		
	//bool bFlag = true;
	//EXPECT_TRUE( bFlag );
}
