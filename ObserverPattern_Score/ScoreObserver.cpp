#include "ScoreObserver.h"
#include "ScoreBoardManagement.h"

Observer::~Observer() {}

DataSheetView::DataSheetView(ScoreRecord * scoreRecord, int viewCount)
 {
	 _scoreRecord = scoreRecord;
	 _viewCount = viewCount;
 }

void DataSheetView::displayScores(list<int>& record, int viewCount)
 {
	 cout << "list of " << viewCount << " entries: ";
	 for (auto &e : record)
	 {
		 cout << e << " ";
	 }
	 cout << endl;
 }

void DataSheetView::update()
  {
	  list<int> record = _scoreRecord->getScoreRecord();
	  displayScores(record, _viewCount);
  }

ScoreMinMaxView::ScoreMinMaxView(ScoreRecord * scoreRecord)
  {
	  _scoreRecord = scoreRecord;
  }

void ScoreMinMaxView::displayMinMax(list<int>& record)
   {
	   int min = *min_element(record.begin(), record.end());
	   int max = *max_element(record.begin(), record.end());

	   cout << "min: " << min << ", max : " << max << endl;
   }

void ScoreMinMaxView::update()
{
	list<int> record;
	record = _scoreRecord->getScoreRecord();
	displayMinMax(record);
}
