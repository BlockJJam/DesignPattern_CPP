#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ElevatorController;

class ElevatorObserver
{
public:
	virtual void update() = 0;
	virtual ~ElevatorObserver() {}
};

class ElevatorDisplay :public ElevatorObserver
{
private:
	ElevatorController *_elevator;

public:
	ElevatorDisplay(ElevatorController *elevator);

	void update() override;
};

class FloorDisplay :public ElevatorObserver
{
private:
	ElevatorController *_elevator;

public:
	FloorDisplay(ElevatorController *elevator);

	void update() override;
};

class VoiceNotice : public ElevatorObserver
{
private:
	ElevatorController *_elevator;

public:
	VoiceNotice(ElevatorController *elevator);

	void update() override;
};

class ControlRoomDisplay : public ElevatorObserver
{
private:
	ElevatorController *_elevator;

public:
	ControlRoomDisplay(ElevatorController *elevator);

	void update() override;
};