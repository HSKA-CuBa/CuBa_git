/**
 * @file	CControlComponent.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CCONTORLCOMPONENT_H
#define CCONTROLCOMPONENT_H
#include "AComponentBase.h"
#include "CControlFSM.h"

class CControlComponent : public AComponentBase
{
public:
	void run() override;
	void init() override;
public:
	CControlComponent();
	CControlComponent(const CControlComponent&) = delete;
	CControlComponent& operator=(const CControlComponent&) = delete;
	~CControlComponent() = default;
private:
	CControlFSM mFSM;
};

#endif
