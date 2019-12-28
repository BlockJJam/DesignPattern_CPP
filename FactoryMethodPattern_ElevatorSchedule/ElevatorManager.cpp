#include "ElevatorManager.h"
#include "ElevatorSchedule.h"

ElevatorController::ElevatorController(int id)
{
	_id = id;
}

void ElevatorController::gotoFloor(int destination)
{
	_curFloor = destination;
	cout << "Elevator [" << _id << "] Floor : " << _curFloor;
}

 ElevatorManager::ElevatorManager(int controllerCount)
{
	_controllers.resize(controllerCount);
	for (int i = 0; i < controllerCount; i++)
	{
		ElevatorController *controller = new ElevatorController(i + 1);
		_controllers[i] = *controller;
	}
}

 void ElevatorManager::requestElevator(int destination, Direction direction)
{
	ElevatorScheduler *scheduler = getScheduler();
	int selectedElevator = scheduler->selectElevator(this, destination, direction);
	_controllers[selectedElevator].gotoFloor(destination);
}

 ElevatorManagerWithThroughputScheduling::ElevatorManagerWithThroughputScheduling(int controllerCount)
	: ElevatorManager(controllerCount)
{}

 ElevatorScheduler * ElevatorManagerWithThroughputScheduling::getScheduler() const
{
	ElevatorScheduler * scheduler = ThroughputScheduler::getInstance();
	return scheduler;
}

 ElevatorManagerWithResponseTimeScheduling::ElevatorManagerWithResponseTimeScheduling(int controllerCount)
	: ElevatorManager(controllerCount)
{}

 ElevatorScheduler * ElevatorManagerWithResponseTimeScheduling::getScheduler() const
{
	ElevatorScheduler * scheduler = ResponseTimeScheduler::getInstance();
	return scheduler;
}
