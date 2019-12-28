#pragma once

#include <iostream>
#include <vector>

using namespace std;

class ElevatorManager;
enum class Direction;

class ElevatorScheduler
{
public:
	virtual int selectElevator(ElevatorManager *manager, int destination, Direction direction) = 0;

	~ElevatorScheduler();
};

class ThroughputScheduler : public ElevatorScheduler
{
private:
	static ElevatorScheduler *_scheduler;

	ThroughputScheduler();

public:
	static ElevatorScheduler * getInstance();
	int selectElevator(ElevatorManager *manager, int destination, Direction direction) override
	{
		return 0;
	}
};

//ElevatorScheduler* ThroughputScheduler::_scheduler = nullptr;

class ResponseTimeScheduler : public ElevatorScheduler
{
private:
	static ElevatorScheduler *_scheduler;

	ResponseTimeScheduler();

public:
	static ElevatorScheduler* getInstance();
	int selectElevator(ElevatorManager *manager, int destination, Direction direction) override
	{
		return 0;
	}
};