#pragma once
#include <iostream>

class ButtonCommand
{
public:
	virtual void execute() = 0;
	virtual ~ButtonCommand() {}
};

class Power
{
private:
	bool _powerStatus = false;
public:

	void setPower(bool powerStatus)
	{
		_powerStatus = powerStatus;
	}

	bool const & getPower()
	{
		return _powerStatus;
	}

	void power()
	{
		if (_powerStatus == false)
		{
			std::cout << "Power On" << std::endl;
			setPower(true);
		}
		else
		{
			std::cout << "Power Off" << std::endl;
			setPower(false);
		}
	}
};

class PowerOnCommand : public ButtonCommand
{
private:
	Power *_thePower;

public:
	PowerOnCommand(Power *thePower)
	{
		this->_thePower = thePower;
	}
	void execute() override
	{
		_thePower->power();
	}
};

class Mute
{
private:
	bool _muteStatus = false;

public:
	void setMute(bool muteStatus)
	{
		_muteStatus = muteStatus;
	}

	bool const & getMute()
	{
		return _muteStatus;
	}

	void mute()
	{
		if (_muteStatus == false)
		{
			std::cout << "Mute On" << std::endl;
			setMute(true);
		}
		else
		{
			std::cout << "Mute Off" << std::endl;
			setMute(false);
		}
	}
};

class MuteOnCommand : public ButtonCommand
{
private:
	Mute *_theMute;

public:
	MuteOnCommand(Mute *theMute)
	{
		this->_theMute = theMute;
	}
	void execute() override
	{
		_theMute->mute();
	}
};