/**
 * @file STimer.h
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Class definition of a timer task which is implemented as a singleton.
 */
#ifndef STIMER_H
#define STIMER_H
#include "IRunnable.h"
#include "CMutex.h"
#include "CCountingSemaphore.h"
#include "Global.h"

class STimer : public IRunnable
{
public:
	/**
	 * Static method to get the singleton instance, may block the calling thread.
	 */
	static STimer& getInstance();
	void run() override;
	void init() override;
	/**
	 * Method to start the timer.
	 * param[in] waitForever 	Specifies whether the called wants to wait for ever to start the timer.
	 * return 					Returns whether the timer was started succesfully.
	 */
	bool start(bool waitForever);
	/**
	 * Method to stop the timer.
	 * param[in] waitForever	Specifies whether the caller wants to wait for ever to stop the timer.
	 * return 					Returns whether the timer was stopped successfully.
	 */
	bool stop(bool waitForever);
public:
	STimer(const STimer&) = delete;
	STimer& operator=(const STimer&) = delete;
	~STimer() = default;
private:
	STimer();
private:
	static STimer* sInstance;
	static CMutex sAccessMutex;
	CCountingSemaphore mRunningSem;
};

#endif
