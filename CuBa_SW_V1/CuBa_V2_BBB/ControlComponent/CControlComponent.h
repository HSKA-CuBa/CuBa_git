/**
 * @file	CControlComponent.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for the control component.
 */
#ifndef CCONTROLCOMPONENT_H
#define CCONTROLCOMPONENT_H
#include "AComponentBase.h"
#include "CControlFSM.h"

class CControlComponent : public AComponentBase
{
public:
	void init() override;
	void run() override;
public:
	CControlComponent(CProxy& proxy);
	CControlComponent(const CControlComponent&) = delete;
	CControlComponent& operator=(const CControlComponent) = delete;
	~CControlComponent() = default;
private:
	CControlFSM mFSM;
};

#endif
