#include <mutex>
#include <condition_variable>

class RWLock
{
public:
	RWLock() = default;
	RWLock(const RWLock& ) = delete;
	const RWLock& operator=(const RWLock& ) = delete;

public:
	bool read_lock();
	bool write_lock();

	bool read_unlock();
	bool write_unlock();

private:
	std::mutex read_mu_;
	std::mutex write_mu_;
	std::condition_variable cv_read_;
	std::condition_variable cv_write_;
	int nWaiting_write_cnt_;
	bool bWritting_;
	int nRead_cnt_;
};
