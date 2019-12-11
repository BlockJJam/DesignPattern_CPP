#pragma once
#include "iostream"
#include "string"

using namespace std;

class Command
{
public:
	virtual void execute() = 0;
	virtual ~Command() {}
};

class Lamp
{
public:
	void turnOn()
	{
		cout << "Lamp On" << endl;
	}
};

class LampOnCommand :public Command
{
private:
	Lamp *_theLamp;

public:
	LampOnCommand(Lamp * theLamp)
	{
		this->_theLamp = theLamp;
	}

	void execute() override
	{
		_theLamp->turnOn();
	}
};

class Alarm
{
public:
	void start()
	{
		cout << "Alaraming.... " << endl;
	}
};

class AlarmOnCommand : public Command
{
private :
	Alarm * _theAlarm;
	
public:
	AlarmOnCommand(Alarm * theAlarm)
	{
		this->_theAlarm = theAlarm;
	}
	
	void execute() override
	{
		_theAlarm->start();
	}
};

class Button
{
private :
	Command * _theCommand;

public:
	Button( Command * theCommand)
	{
		this->_theCommand = theCommand;
	}
	
	void setCommand(Command *newCommand)
	{
		this->_theCommand = newCommand;
	}

	void pressed()
	{
		_theCommand->execute();
	}
};