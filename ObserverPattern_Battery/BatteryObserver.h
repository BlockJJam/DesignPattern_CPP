#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Battery;

class BatteryObserver
{
public:
	virtual void update() = 0; 
	virtual ~BatteryObserver();
};

class BatteryLevelDisplay : public BatteryObserver
{
private:
	Battery *_battery;
public:
	BatteryLevelDisplay(Battery *battery);
	void update();
};

class LowBatteryWarning : public BatteryObserver
{
private:
	Battery *_battery;
	static const int _LOW_BATTERY = 30;
public:
	LowBatteryWarning(Battery *battery);

	void update();
};