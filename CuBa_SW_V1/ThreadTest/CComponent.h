/**
 * @file CComponent.h
 */
#ifndef CCOMPONENT_H
#define CCOMPONENT_H
#include "IRunnable.h"
#include "CRxTask.h"
#include "CThread.h"

class CComponent : public IRunnable
{
public:
	void init() override;
	void run() override;
	void pause() override;
	void resume() override;
public:
	CComponent();
	CComponent(const CComponent&) = delete;
	CComponent& operator=(const CComponent&) = delete;
	~CComponent() = default;
private:
	CRxTask mRxTask;
	CThread mRxThread;
};

#endif
