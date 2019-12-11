#pragma once

#include "BatteryObserver.h"
using namespace std;

class BatterySubject
{
private:
	vector<BatteryObserver*> *_batteryObservers = new vector<BatteryObserver*>();

public:
	void attach(BatteryObserver *batteryObserver);

	void detach(BatteryObserver * batteryObserver);

	void notifyObserver();
};

class Battery : public BatterySubject
{
private:
	int _level = 100;

public:
	void consume(int &&amount);

	int & getLevel();
};