#pragma once
#include <iostream>

class MovingStrategy
{
public:
	MovingStrategy() {}
	virtual void move() = 0;
	virtual ~MovingStrategy() {}
};

class WalkingStrategy : public MovingStrategy
{
public:
	WalkingStrategy() {}

	virtual void move()
	{
		std::cout << " I can only walk" << std::endl;
	}
};

class FlyingStrategy : public MovingStrategy
{
public:
	FlyingStrategy(){}

	virtual void move()
	{
		std::cout << " I can only flying" << std::endl;
	}
};