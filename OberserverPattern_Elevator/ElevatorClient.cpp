#include "Elevator.h"

void main()
{
	ElevatorController *controller = new ElevatorController();
	
	ElevatorObserver *elevatorDisplay = new ElevatorDisplay(controller);
	ElevatorObserver *floorDisplay = new FloorDisplay(controller);
	ElevatorObserver *voiceNotice = new VoiceNotice(controller);
	ElevatorObserver *controlRoomDisplay = new ControlRoomDisplay(controller);

	controller->attach(elevatorDisplay);
	controller->attach(floorDisplay);
	controller->attach(voiceNotice);
	controller->attach(controlRoomDisplay);

	controller->gotoFloor(5);
	controller->gotoFloor(7);
}