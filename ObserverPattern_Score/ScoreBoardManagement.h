#pragma once
#include <list>
#include <iostream>
#include <vector>

using namespace std;

class Observer;

class Subject
{
private:
	vector<Observer*> *_observers = new vector<Observer*>();
	
public:
	void attach(Observer *observer);

	void detach(Observer *observer);

	void notifyObservers();
};

class ScoreRecord : public Subject
{
private:
	list<int> _scores;

public:
	void addScore(int score);

	const list<int> & getScoreRecord();
};