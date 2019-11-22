#pragma once

#include <iostream>
#include "VendingState.h"
using namespace std;

class MoneyBox
{
private:
	int _money = 0;

public:
	int getMoney()
	{
		return _money;
	}

	void insert(int money)
	{
		_money += money;
	}

	void dispense(int price)
	{
		_money -= price;
	}

	int returnMoney()
	{
		int returnMoney = _money;
		_money = 0;
		return returnMoney;
	}
};


class Drinking
{
private:
	int _price;
	int _stock;

public:
	Drinking(int stock, int price)
	{
		_stock = stock;
		_price = price;
	}

	void dispense()
	{
		_stock--;
	}

	int getPrice()
	{
		return _price;
	}

	int getStock()
	{
		return _stock;
	}
};

class VendingMachine
{
private:
	VendingState * _noMoneyState;
	VendingState * _noEnoughMoneyState;
	VendingState * _enoughMoneyState;
	VendingState * _soldOutState;
	VendingState * _state;

	MoneyBox * _moneyBox;
	Drinking * _drinking;

public:
	VendingMachine(int stock, int price)
	{
		_noMoneyState = new NoMoneyState(this);
		_noEnoughMoneyState = new NoEnoughMoneyState(this);
		_enoughMoneyState = new EnoughMoneyState(this);
		_soldOutState = new SoldOutState(this);

		_moneyBox = new MoneyBox();
		_drinking = new Drinking(stock, price);
		
		if (_drinking->getStock() > 0)
			_state = _noMoneyState;
		else
			_state = _soldOutState;
	}
	~VendingMachine()
	{
		delete _noMoneyState;
		delete _noEnoughMoneyState;
		delete _enoughMoneyState;
		delete _soldOutState;
	}
	void setState(VendingState * state)
	{
		_state = state;
	}

	void insertMoney(int money)
	{
		_state->insertMoney(money);
	}
	
	void pushButton()
	{
		int _price = _drinking->getPrice();
		_state->pushButton(_price);
	}

	void returnMoney()
	{
		_state->returnMoney();
	}

	MoneyBox & getMoneyBox()
	{
		return * _moneyBox;
	}

	Drinking & getDrinking()
	{
		return * _drinking;
	}

	VendingState & getNoMoneyState()
	{
		return  * _noMoneyState;
	}

	VendingState & getNoEnoughMoneyState()
	{
		return * _noEnoughMoneyState;
	}

	VendingState & getEnoughMoneyState()
	{
		return * _enoughMoneyState;
	}

	VendingState & getSoldOutState()
	{
		return * _soldOutState;
	}
};