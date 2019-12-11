#include "Elevator.h"
#include "ElevatorObserver.h"
void ElevatorSubject::attach(ElevatorObserver * elevatorObserver)
{
	_elevatorObservers->push_back(elevatorObserver);
}

void ElevatorSubject::detach(ElevatorObserver * elevatorObserver)
{
	remove(_elevatorObservers->begin(), _elevatorObservers->end(), elevatorObserver);
}

void ElevatorSubject::notifyObservers()
{
	for (auto &e : *_elevatorObservers)
		e->update();
}

void ElevatorController::gotoFloor(int destination)
{
	_curFloor = destination;
	notifyObservers();
}

int & ElevatorController::getCurFloor()
{
	return _curFloor;
}
