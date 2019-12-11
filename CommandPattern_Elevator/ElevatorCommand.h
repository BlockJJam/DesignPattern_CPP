#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

enum class Direction
{
	DOWN = -1,
	STOP,
	UP
};

class Command
{
public:
	virtual void execute() = 0;
	virtual ~Command() {}
};

class ElevatorController
{
private:
	unsigned int _id = 0;
	int _current_floor = 1;

public:
	ElevatorController(unsigned int id)
	{
		_id = id;
	}
	
	void gotoFloor(int destination)
	{
		_current_floor = destination;
		cout << "this floor is " << destination << endl;
	}
	
	const int &getCurrentFloor()
	{
		return _current_floor;
	}
	const int &getElevatorID()
	{
		return _id;
	}
};

class DestinationSelectionCommand : public Command
{
private:
	int _destination = 1;
	ElevatorController *_elevatorController;

public:
	DestinationSelectionCommand(int destination, ElevatorController *elevatorController)
	{
		_destination = destination;
		_elevatorController = elevatorController;
	}

	void execute() override
	{
		_elevatorController->gotoFloor(_destination);
	}
};

int absFloor(int floor1, int floor2);

class ElevatorManager
{
private:
	unsigned int elevatorAmount = 0;
	vector<ElevatorController> _elevatorController;
	ElevatorController &selectedController = _elevatorController[0];

public:
	ElevatorManager(unsigned int controllerCount)
	{
		elevatorAmount = controllerCount;
	}

	void addController(ElevatorController &controller)
	{
		_elevatorController.push_back(controller);
	}

	void requestElevator(int destination, Direction * direction)
	{
		selectElevator(destination, direction);
		cout << "Please go to " << selectedController.getElevatorID() << " elevator and wait a moment";
	}

private:
	void selectElevator(int destination, Direction *direction)
	{
		for (auto &eleNum : _elevatorController)
		{
			if (absFloor(destination, selectedController.getCurrentFloor()) > absFloor(destination, eleNum.getCurrentFloor()))
				selectedController = eleNum;
		}
	}
};

int absFloor(int floor1, int floor2)
{
	return abs((floor1 - floor2));
}

class ElevatorRequestCommand : public Command
{
private:
	int _destination = 1;
	Direction * _direction;
	ElevatorManager *_elevatorManager;

public:
	ElevatorRequestCommand(int destination, Direction *direction, ElevatorManager * manager)
	{
		_destination = destination;
		_direction = direction;
		_elevatorManager = manager;
	}

	void execute()
	{
		_elevatorManager->requestElevator(_destination, _direction);
	}

};