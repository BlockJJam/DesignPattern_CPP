#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class DoorStatus
{
	OPENED,
	CLOSED
};

enum class MotorStatus
{
	MOVING, 
	STOPPED
};

enum class Direction
{
	UP,
	DOWN,
};

class Door
{
private:
	DoorStatus _doorStatus;

public:
	Door()
	{
		_doorStatus = DoorStatus::CLOSED;
	}

	DoorStatus getDoorStatus() const
	{
		return _doorStatus;
	}

	void close()
	{
		_doorStatus = DoorStatus::OPENED;
	}

	void open()
	{
		_doorStatus = DoorStatus::CLOSED;
	}
};

class Motor
{
private:
	Door _door;
	MotorStatus _motorStatus;

	void setMotorStatus(MotorStatus motorStatus)
	{
		_motorStatus = motorStatus;
	}

protected:
	virtual void moveMotor(Direction &direction) = 0;

public:
	Motor(Door door)
	{
		_door = door;
		_motorStatus = MotorStatus::STOPPED;
	}

	MotorStatus getMotorStatus() const
	{
		return _motorStatus;
	}

	void move(Direction direction)
	{
		MotorStatus motorStatus = getMotorStatus();
		if (motorStatus == MotorStatus::MOVING)
			return;

		DoorStatus doorStatus = _door.getDoorStatus();
		if (doorStatus == DoorStatus::OPENED)
			_door.close();

		moveMotor(direction);
		setMotorStatus(MotorStatus::MOVING);
	}
};

class HyundaiMotor : public Motor
{
private:

public:
	HyundaiMotor(Door door)
		: Motor(door)
	{}

	void moveMotor(Direction &direction) override
	{
		if (direction == Direction::UP)
			cout << " Hyndai Motor move UP" << endl;
		else
			cout << " Hyundai Motor move DOWN" << endl;
	}
};

class LGMotor : public Motor
{
private:

public:
	LGMotor(Door door)
		: Motor(door)
	{}

	void moveMotor(Direction & direction) override
	{
		if (direction == Direction::UP)
			cout << " LG Motor move UP" << endl;
		else
			cout << " LG Motor move DOWN" << endl;
	}
};
