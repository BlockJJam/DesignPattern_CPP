#include "ElevatorObserver.h"
#include "Elevator.h"

ElevatorDisplay::ElevatorDisplay(ElevatorController * elevator)
{
	_elevator = elevator;
}

void ElevatorDisplay::update()
{
	int curFloor = _elevator->getCurFloor();
	cout << "Elevator display: " << curFloor << endl;
}

FloorDisplay::FloorDisplay(ElevatorController * elevator)
{
	_elevator = elevator;
}

void FloorDisplay::update()
{
	int curFloor = _elevator->getCurFloor();
	cout << "Floor display : " << curFloor << endl;
}

VoiceNotice::VoiceNotice(ElevatorController * elevator)
{
	_elevator = elevator;
}

void VoiceNotice::update()
{
	int curFloor = _elevator->getCurFloor();
	cout << "Voice Notice : " << curFloor << endl;
}

ControlRoomDisplay::ControlRoomDisplay(ElevatorController * elevator)
{
	_elevator = elevator;
}

void ControlRoomDisplay::update()
{
	int curFloor = _elevator->getCurFloor();
	cout << "Control Room : " << curFloor << endl;
}
