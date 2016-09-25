/**
 * @file 	CCommComponent.h
 * @author	Michael Meindl
 * @date 	25.9.2016
 * @brief	Class definition for the comm task.
 */
#ifndef CCOMMCOMPONENT_H
#define CCOMMCOMPONENT_H
#include <CProxy.h>
#include "AComponentBase.h"
#include "CMutex.h"

class CCommComponent : public AComponentBase
{
public:
	void init() override;
	void onStateRunning(CMessage& msg) override;
	void onStateStandby(CMessage& msg) override;
public:
	CCommComponent(const CCommComponent&) = delete;
	CCommComponent& operator=(const CCommComponent&) = delete;
	~CCommComponent() = default;
	CCommComponent();
};

#endif
