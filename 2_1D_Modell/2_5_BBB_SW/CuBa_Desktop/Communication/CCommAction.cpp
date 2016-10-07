/**
 * @file	CCommAction.cpp
 * @author  Michael Meindl
 * @date	6.10.2016
 */
#include "CCommAction.h"
#include <iostream>
using namespace std;

CCommAction::CCommAction()
{

}
void CCommAction::entryStandby()
{
	cout << "[*] Comm-FSM: Entering Standby" << endl;
}
void CCommAction::exitStandby()
{
	cout << "[*] Comm-FSM: Exiting Standby" << endl;
}
void CCommAction::entryRunning()
{
	cout << "[*] Comm-FSM: Entering Running" << endl;
}
void CCommAction::exitRunning()
{
	cout << "[*] Comm-FSM: Exiting Running" << endl;
}
void CCommAction::transmitMessage(CMessage& msg)
{
	cout << "[*] Comm-FSM: Transmitting Message" << endl;
}
