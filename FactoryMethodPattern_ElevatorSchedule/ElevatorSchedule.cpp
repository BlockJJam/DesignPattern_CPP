#include "ElevatorSchedule.h"
#include "ElevatorManager.h"

 ElevatorScheduler::~ElevatorScheduler()
{}

 ThroughputScheduler::ThroughputScheduler() {}

 ElevatorScheduler * ThroughputScheduler::getInstance()
{
	if (_scheduler == nullptr)
		_scheduler = new ThroughputScheduler();

	return _scheduler;
}
 ElevatorScheduler* ThroughputScheduler::_scheduler = nullptr;

 ResponseTimeScheduler::ResponseTimeScheduler() {}

 ElevatorScheduler * ResponseTimeScheduler::getInstance()
{
	if (_scheduler == nullptr)
		_scheduler = new ResponseTimeScheduler();

	return _scheduler;
}

 ElevatorScheduler* ResponseTimeScheduler::_scheduler = nullptr;
