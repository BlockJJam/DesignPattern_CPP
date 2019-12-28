#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ElevatorScheduler;

enum class Direction
{
	UP,
	DOWN,
	STOP
};

class ElevatorController
{
private:
	int _id;
	int _curFloor = 0;

public:
	ElevatorController() {}
	ElevatorController(int id);

	void gotoFloor(int destination);
};

class ElevatorManager
{
private:
	vector<ElevatorController> _controllers;

public:
	ElevatorManager(int controllerCount);

protected:
	virtual ElevatorScheduler *getScheduler() const = 0;

public:
	void requestElevator(int destination, Direction direction);
};

class ElevatorManagerWithThroughputScheduling : public ElevatorManager
{
public:
	ElevatorManagerWithThroughputScheduling(int controllerCount);

protected:
	ElevatorScheduler * getScheduler() const override;
};

class ElevatorManagerWithResponseTimeScheduling : public ElevatorManager
{
public:
	ElevatorManagerWithResponseTimeScheduling(int controllerCount);

protected:
	ElevatorScheduler * getScheduler() const override;
};