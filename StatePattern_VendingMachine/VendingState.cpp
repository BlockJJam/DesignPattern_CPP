#include "VendingState.h"
#include "VendingMachine.h"

NoMoneyState::NoMoneyState(VendingMachine * machine)
{
	_machine = machine;
}

NoMoneyState::~NoMoneyState()
{
	delete _machine;
}

void NoMoneyState::insertMoney(int money)
{
	_machine->getMoneyBox().insert(money);
	cout << _machine->getMoneyBox().getMoney() << " won insert! " << endl;

	if (money >= _machine->getDrinking().getPrice())
	{
		_machine->setState(&_machine->getEnoughMoneyState());
	}
	else
	{
		_machine->setState(&_machine->getNoEnoughMoneyState());
	}
	cout << "current money is " << _machine->getMoneyBox().getMoney() << " won" << endl;
}

void NoMoneyState::pushButton(int price)
{
	cout << "Please insert money " << endl;
}

void NoMoneyState::returnMoney()
{
	cout << "No return Money" << endl;
}

NoEnoughMoneyState::NoEnoughMoneyState(VendingMachine * machine)
{
	_machine = machine;
}

NoEnoughMoneyState::~NoEnoughMoneyState()
{
	delete _machine;
}

void NoEnoughMoneyState::insertMoney(int money)
{
	_machine->getMoneyBox().insert(money);
	cout << _machine->getMoneyBox().getMoney() << " won insert!!" << endl;

	if (_machine->getMoneyBox().getMoney() >= _machine->getDrinking().getPrice())
	{
		_machine->setState(&_machine->getEnoughMoneyState());
	}
	else
	{
		_machine->setState(&_machine->getNoEnoughMoneyState());
	}
	cout << "current money is " << _machine->getMoneyBox().getMoney() <<" won"<< endl;
}

void NoEnoughMoneyState::pushButton(int price)
{
	cout << "you need to push more money " << endl;
}

void NoEnoughMoneyState::returnMoney()
{
	int returnMoneyToClient = _machine->getMoneyBox().returnMoney();
	cout << returnMoneyToClient << " won return " << endl;
	_machine->setState(&_machine->getNoMoneyState());
}

EnoughMoneyState::EnoughMoneyState(VendingMachine * machine)
{
	_machine = machine;
}

EnoughMoneyState::~EnoughMoneyState()
{
	delete _machine;
}

void EnoughMoneyState::insertMoney(int money)
{
	_machine->getMoneyBox().insert(money);
	cout << _machine->getMoneyBox().getMoney() << " won insert!!! " << endl;
	cout << "current money is " << _machine->getMoneyBox().getMoney() <<" won "<< endl;
}

void EnoughMoneyState::pushButton(int price)
{
	_machine->getMoneyBox().dispense(price);
	_machine->getDrinking().dispense();
	cout << "Drink is out~! " << endl;

	if (_machine->getDrinking().getStock() == 0)
	{
		_machine->setState(&_machine->getSoldOutState());
	}
	else if (_machine->getMoneyBox().getMoney() < _machine->getDrinking().getPrice())
	{
		_machine->setState(&_machine->getNoEnoughMoneyState());
	}
	else if (_machine->getMoneyBox().getMoney() == 0)
	{
		_machine->setState(&_machine->getNoMoneyState());
	}
}

void EnoughMoneyState::returnMoney()
{
	int returnMoneyToClient = _machine->getMoneyBox().returnMoney();
	cout << returnMoneyToClient << " won return " << endl;
	_machine->setState(&_machine->getNoMoneyState());
}

SoldOutState::SoldOutState(VendingMachine * machine)
{
	_machine = machine;
}

SoldOutState::~SoldOutState()
{
	delete _machine;
}

void SoldOutState::insertMoney(int money)
{
	cout << "Sorry, Out of Stock" << endl;
}

void SoldOutState::pushButton(int price)
{
	cout << "Nothing" << endl;
}

void SoldOutState::returnMoney()
{
	int returnMoneyToClient = _machine->getMoneyBox().returnMoney();
	cout << returnMoneyToClient << " won return " << endl;
	_machine->setState(&_machine->getNoMoneyState());
}
