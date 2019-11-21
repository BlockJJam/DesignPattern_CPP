#include "Robot.h"

Robot::Robot(const std::string robot_name)
	: _name(robot_name)
{}

std::string Robot::getName()
{
	return _name;
}

void Robot::move()
{
	_movingStrategy->move();
}

void Robot::attack()
{
	_attackingStrategy->attack();
}

void Robot::setMovingStrategy(MovingStrategy * movingStrategy)
{
	_movingStrategy = movingStrategy;
}

void Robot::setAttackingStrategy(AttackingStrategy  *attackingStrategy)
{
	_attackingStrategy = attackingStrategy;
}

Atom::Atom(const std::string robot_name)
	: Robot(robot_name)
{}

TaekwonV::TaekwonV(const std::string robot_name)
	: Robot(robot_name)
{}
