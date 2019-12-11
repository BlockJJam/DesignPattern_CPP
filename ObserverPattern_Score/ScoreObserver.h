#pragma once
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class ScoreRecord;

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer();
};

class DataSheetView : public Observer
{
private:
	ScoreRecord *_scoreRecord;
	int _viewCount = 0;

public:
	DataSheetView(ScoreRecord *scoreRecord, int viewCount);

	void displayScores(list<int> &record, int viewCount);

	void update() override;
};

class ScoreMinMaxView : public Observer
{
private:
	ScoreRecord *_scoreRecord;

public:
	ScoreMinMaxView(ScoreRecord * scoreRecord);

	void displayMinMax(list<int> &record);

	void update() override;
};
