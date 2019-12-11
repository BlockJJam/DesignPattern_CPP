#pragma once
#include "ElevatorObserver.h"
using namespace std;

class ElevatorSubject
{
private:
	vector<ElevatorObserver*> *_elevatorObservers = new vector<ElevatorObserver*>();

public:
	void attach(ElevatorObserver *elevatorObserver);

	void detach(ElevatorObserver *elevatorObserver);

	void notifyObservers();
};

class ElevatorController : public ElevatorSubject
{
private:
	int _curFloor = 1;

public:
	void gotoFloor(int destination);

	int & getCurFloor();
};