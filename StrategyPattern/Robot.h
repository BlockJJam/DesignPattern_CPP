#pragma once

#include "MovingStrategy.h"
#include "AttackingStrategy.h"

#include <iostream>
#include <string>

class Robot
{
private:
	std::string _name;
	MovingStrategy *_movingStrategy ;
	AttackingStrategy *_attackingStrategy;

public:
	Robot(const std::string robot_name);

	virtual std::string getName();

	void move();
	void attack();

	void setMovingStrategy(MovingStrategy  *movingStrategy);
	void setAttackingStrategy( AttackingStrategy *attackingStrategy);
};

class Atom : public Robot
{
public:
	Atom(const std::string robot_name);
};

class TaekwonV : public Robot
{
public:
	TaekwonV(const std::string robot_name);
};