#pragma once

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class CarComponent
{
public:
	virtual const int & getPrice() = 0;
	virtual const string getString() = 0;
	virtual ~CarComponent() {}
};

class BasicCar : public CarComponent
{
private:
	int _price = 0;
public:
	BasicCar(int price)
	{
		_price = price;
	}

	const int & getPrice() override
	{
		return _price;
	}

	const string getString() override
	{
		return "Car";
	}
};

class CarOptionDecorator : public CarComponent
{
private:
	CarComponent *_decoratedCar;

public:
	CarOptionDecorator(CarComponent *decoratedCar)
	{
		_decoratedCar = decoratedCar;
	}
	
	const int & getPrice() override
	{
		return _decoratedCar->getPrice();
	}

	const string getString() override
	{
		return _decoratedCar->getString();
	}
};

class AirBagDecorator : public CarOptionDecorator
{
private:
	CarComponent *_decoratedCar;
	int _airBagPrice = 0;

	const int & getAirBagPrice()
	{
		return _airBagPrice;
	}

public:
	AirBagDecorator(CarComponent * decoratedCar, int airBagPrice)
		: CarOptionDecorator(decoratedCar)
	{
		_decoratedCar = decoratedCar;
		_airBagPrice = airBagPrice;
	}

	const int & getPrice() override
	{
		int decoratedCarPrice = _decoratedCar->getPrice();
		int airBagPrice = getAirBagPrice();
		return  decoratedCarPrice + airBagPrice;
	}

	const string getString() override
	{
		return _decoratedCar->getString() + " with Air Bag";
	}
};

class ESCDecorator : public CarOptionDecorator
{
private:
	CarComponent *_decoratedCar;
	int _escPrice = 0;
	
	const int & getESCPrice()
	{
		return _escPrice;
	}

public:
	ESCDecorator(CarComponent * decoratedCar, int escPrice)
		: CarOptionDecorator(decoratedCar)
	{
		_decoratedCar = decoratedCar;
		_escPrice = escPrice;
	}

	const int & getPrice() override
	{
		int decoratedCarPrice = _decoratedCar->getPrice();
		int escPrice = getESCPrice();
		return decoratedCarPrice + escPrice;
	}

	const string getString() override
	{
		return _decoratedCar->getString() + " with Electronic Stability Control";
	}
};