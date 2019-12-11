#include "TvButton.h"
using namespace std;

int main()
{
	Power *power = new Power();
	Mute *mute = new Mute();

	ButtonCommand *powerButton = new PowerOnCommand(power);
	ButtonCommand *muteButton = new MuteOnCommand(mute);

	TvButton *button1 = new TvButton(powerButton, muteButton);
	TvButton *button2 = new TvButton(powerButton, powerButton);

	cout << "button1" << endl << endl;
	button1->button1Pressed();
	button1->button1Pressed();
	button1->button1Pressed();
	button1->button2Pressed();
	button1->button2Pressed();
	

	cout << endl << "button2" << endl;
	button2->button1Pressed();
	button2->button1Pressed();
	button2->button2Pressed();
	button2->button2Pressed();


	return 0;
}