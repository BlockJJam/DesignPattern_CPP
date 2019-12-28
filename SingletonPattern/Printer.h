#pragma once
#include <thread>
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;



class Printer
{
public:
	virtual void print(string str)=0;
	virtual ~Printer() {};
};

class RealPrinter99 : public Printer
{
private:
	static Printer* _printer ;
public:
	~RealPrinter99()
	{}

	static Printer & getPrinter();
	
	void print(string str)
	{
		//TODO: printer's printing algorithm
		cout << str << endl;
	}
};

Printer* RealPrinter99::_printer=nullptr;

Printer & RealPrinter99::getPrinter()
{
	if (_printer == nullptr)
		_printer = new RealPrinter99();
	return *_printer;
}

class FakePrinter : public Printer
{
private:
	string _str;

public:
	void print(string str)
	{
		_str = str;
	}

	string get()
	{
		return _str;
	}
};

class UsePrinter
{
public:
	void doSomething(Printer &printer)
	{
		string str;
		str = " hello, client";

		printer.print(str);
	}
};