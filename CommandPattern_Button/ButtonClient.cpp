#include "Button.h"

using namespace std;

int main()
{
	Lamp *lamp = new Lamp();
	Command *lampOnCommand = new LampOnCommand(lamp);

	Button *button1 = new Button(lampOnCommand);
	button1->pressed();

	Alarm *alarm = new Alarm();
	Command *alarmOnCommand = new AlarmOnCommand(alarm);

	button1->setCommand(alarmOnCommand);
	button1->pressed();

	Button *button2 = new Button(alarmOnCommand);
	button2->pressed();

	return 0;
}