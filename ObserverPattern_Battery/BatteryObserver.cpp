#include "BatteryObserver.h"
#include "Battery.h"

BatteryObserver::~BatteryObserver() {}

BatteryLevelDisplay::BatteryLevelDisplay(Battery * battery)
{
	_battery = battery;
}

void BatteryLevelDisplay::update()
{
	int level = _battery->getLevel();
	cout << "Level: " << level << endl;
}

LowBatteryWarning::LowBatteryWarning(Battery * battery)
{
	_battery = battery;
}

void LowBatteryWarning::update()
{
	int level = _battery->getLevel();
	if (level < _LOW_BATTERY)
		cout << "<Warning> Low Battery : " << level << " compared with " << _LOW_BATTERY << endl;
}
