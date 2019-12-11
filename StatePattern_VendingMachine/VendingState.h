#pragma once

#include <iostream>
using namespace std;

class VendingMachine;

class VendingState
{
public:
	virtual void insertMoney(int money) = 0;
	virtual void pushButton(int price) = 0;
	virtual void returnMoney() = 0;
	virtual ~VendingState() {}
};

class NoMoneyState : public VendingState
{
private:
	VendingMachine * _machine;

public:
	NoMoneyState(VendingMachine * machine);
	~NoMoneyState();

	void insertMoney(int money);
	void pushButton(int price);
	void returnMoney();
};

class NoEnoughMoneyState : public VendingState
{
private:
	VendingMachine * _machine;

public:
	NoEnoughMoneyState(VendingMachine * machine);
	~NoEnoughMoneyState();

	void insertMoney(int money);
	void pushButton(int price);
	void returnMoney();
};

class EnoughMoneyState :public VendingState
{
private:
	VendingMachine * _machine;

public:
	EnoughMoneyState(VendingMachine * machine);
	~EnoughMoneyState();
	
	void insertMoney(int money);
	void pushButton(int price);
	void returnMoney();
};

class SoldOutState :public VendingState
{
private:
	VendingMachine * _machine;

public:
	SoldOutState(VendingMachine * machine);
	~SoldOutState();

	void insertMoney(int money);
	void pushButton(int price);
	void returnMoney();
};
