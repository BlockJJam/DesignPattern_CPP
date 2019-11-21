#pragma once

#include <iostream>

class AttackingStrategy
{
public:
	virtual void attack() = 0;
	virtual ~AttackingStrategy() {}
};

class MissileStrategy : public AttackingStrategy
{
public:
	MissileStrategy() {}

	virtual void attack()
	{
		std::cout << " I have Missile and can atttack with it." << std::endl;
	}
};

class PunchStrategy : public AttackingStrategy
{
public:
	PunchStrategy() {}

	virtual void attack()
	{
		std::cout << " I have strong punch and can atttack with it." << std::endl;
	}
};