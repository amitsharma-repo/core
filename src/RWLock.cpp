#include <RWLock.h>

bool RWLock::read_lock()
{
	
	std::unique_lock<std::mutex>   lck(read_mu_);

	//wait for no write in CS and no waiting of writer to enter CS
	cv_read_.wait(lck, [](){ return !( bWritting_ && nWaiting_write_cnt_ >0); });
	nRead_cnt_				+=		1;
	lck.unlock();
}
bool RWLock::write_lock()
{
	std::unique_lock<std::mutex> 	lck(write_mu_);
	nWaiting_write_cnt_     +=		1;

	//wait for no reader in CS and no write in CS
	cv_write_.wait(lck, [](){nRead_Cnt != 0 && bWritting_;}
	nWaiting_write_cnt_ 	-= 		1;
	bWritting_ 				 = 		true;
	lck.unlock();	
}
bool RWLock::read_unlock()
{
	std::unique_lock<std::mutex>  	lck(read_mu_);
	nRead_cnt_ 				-=		1;
	if(!nWriteStatus)
	{
		//notify all readers
		cv_read_.notify_all();		
	}
	lck.unlock();
}
bool RWLock::write_unlock()
{
	std::unique_lock<std::mutex> 	lck(write_mu_);
	bWritting_ 				=		true;
	//notigy latest writer in waiting list
	cv_write.notify_once();
	//notify all readers
	cv_read_.notify_all();
	lck.unlock();
}

