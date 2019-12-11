#include "ScoreBoardManagement.h"
#include "ScoreObserver.h"

void Subject::attach(Observer *observer)
{
	_observers->push_back((Observer*)observer);
}

void Subject::detach(Observer * observer)
{
	remove(_observers->begin(), _observers->end(), observer);			
}

 void Subject::notifyObservers()
 {
	 for (auto &observer : *_observers)
		 observer->update();
 }

 void ScoreRecord::addScore(int score)
 {
	 _scores.push_back(score);
	 notifyObservers();
 }

 const list<int>& ScoreRecord::getScoreRecord()
 {
	 return _scores;
 }
