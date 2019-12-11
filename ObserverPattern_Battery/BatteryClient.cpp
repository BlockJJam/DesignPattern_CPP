#include "Battery.h"


void main()
{
	Battery *battery = new Battery();
	BatteryObserver *batteryDisplay = new BatteryLevelDisplay(battery);
	BatteryObserver *lowBatteryWarning = new LowBatteryWarning(battery);

	battery->attach(batteryDisplay);

	battery->attach(lowBatteryWarning);

	battery->consume(10);
	battery->consume(20);
	battery->consume(45);

	battery->detach(batteryDisplay);
	battery->detach(lowBatteryWarning);
}