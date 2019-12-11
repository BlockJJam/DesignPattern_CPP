#include "Battery.h"
#include "BatteryObserver.h"

void BatterySubject::attach(BatteryObserver * batteryObserver)
{
	_batteryObservers->push_back(batteryObserver);
}

void BatterySubject::detach(BatteryObserver * batteryObserver)
{
	remove(_batteryObservers->begin(), _batteryObservers->end(), batteryObserver);
}

void BatterySubject::notifyObserver()
{
	for (BatteryObserver* & batteryObserver : *_batteryObservers)
	{
		batteryObserver->update();
	}
}

void Battery::consume(int && amount)
{
	_level -= amount;
	notifyObserver();
}

int & Battery::getLevel()
{
	return _level;
}
