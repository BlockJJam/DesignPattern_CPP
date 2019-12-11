#pragma once
#include "ButtonCommand.h"

class TvButton
{
private:
	ButtonCommand *_buttonCommand1;
	ButtonCommand *_buttonCommand2;

public:
	TvButton(ButtonCommand *buttonCommand1, ButtonCommand *buttonCommand2)
	{
		this->_buttonCommand1 = buttonCommand1;
		this->_buttonCommand2 = buttonCommand2;
	}

	void setButton(ButtonCommand * command1, ButtonCommand *command2)
	{
		this->_buttonCommand1 = command1;
		this->_buttonCommand2 = command2;
	}

	void button1Pressed()
	{
		_buttonCommand1->execute();
	}
	
	void button2Pressed()
	{
		_buttonCommand2->execute();
	}

};