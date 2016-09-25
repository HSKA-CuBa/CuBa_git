/**
 * @file 	CControlComponent.h
 * @author 	Michael Meindl
 * @date	25.9.2016
 * @brief 	Class definition for the control component.
 */
#ifndef CCONTROLCOMPONENT_H
#define CCONTROLCOMPONENT_H
#include <CProxy.h>
#include "AComponentBase.h"
#include "CMutex.h"

/**
 * Class to represent the control task.
 * Inherits from AComponentBase and and implements the init() and run() method.
 */
class CControlComponent : public AComponentBase
{
public:
	/**
	 * Initialize the hardware.
	 */
	void init() override;
	void onStateRunning(CMessage& msg) override;
	void onStateStandby(CMessage& msg) override;
public:
	CControlComponent(const CControlComponent&) = delete;
	CControlComponent& operator=(const CControlComponent&) = delete;
	~CControlComponent() = default;
	CControlComponent();
};
#endif
