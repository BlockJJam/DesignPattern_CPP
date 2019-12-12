#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Display
{
public:
	virtual void draw() = 0;
	virtual ~Display() {}
};

class RoadDisplay : public Display
{
public:
	void draw() override
	{
		cout << "�⺻ ���� ǥ�� " << endl;
	}
};

class DisplayDecorator : public Display
{
private:
	Display *_decoratedDisplay;

public:
	DisplayDecorator(Display * decoratedDisplay)
	{
		_decoratedDisplay = decoratedDisplay;
	}

	void draw() override
	{
		_decoratedDisplay->draw();
	}
};

class LaneDecorator : public DisplayDecorator
{
private:
	Display *_decoratedDisplay;

	void drawLane()
	{
		cout << "\t���� ǥ��" << endl;
	}

public:
	LaneDecorator(Display * decoratedDisplay)
		: DisplayDecorator(decoratedDisplay)
	{
		_decoratedDisplay = new DisplayDecorator(decoratedDisplay);
	}

	void draw() override
	{
		_decoratedDisplay->draw();
		drawLane();
	}
};

class TrafficDecorator : public DisplayDecorator
{
private:
	Display *_decoratedDisplay;
	void drawTraffic()
	{
		cout << "\t���뷮 ǥ��" << endl;
	}

public:
	TrafficDecorator(Display *decoratedDisplay)
		: DisplayDecorator(decoratedDisplay)
	{
		_decoratedDisplay = new DisplayDecorator(decoratedDisplay);
	}

	void draw() override
	{
		_decoratedDisplay->draw();
		drawTraffic();
	}
};