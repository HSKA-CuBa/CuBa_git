/**
 * @file CTimer.h
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Class definition of a timer task.
 */
#ifndef CTIMER_H
#define CTIMER_H
#include <CProxy.h>
#include "IRunnable.h"
#include "CMutex.h"
#include "CCountingSemaphore.h"
#include "Global.h"

class CTimer : public IRunnable
{
public:
	void run() override;
	bool setProxy(CProxy& proxy);
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
	CTimer(const CTimer&) = delete;
	CTimer& operator=(const CTimer&) = delete;
	~CTimer() = default;
	CTimer();
private:
	CCountingSemaphore mRunningSem;
	CProxy* mProxyPtr;
};

#endif