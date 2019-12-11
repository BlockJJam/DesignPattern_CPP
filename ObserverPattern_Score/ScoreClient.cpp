#include "ScoreBoardManagement.h"
#include "ScoreObserver.h"
using namespace std;

int main()
{
	ScoreRecord *scoreRecord = new ScoreRecord();
	DataSheetView *dataSheetView3 = new DataSheetView(scoreRecord, 3);
	DataSheetView *dataSheetView5 = new DataSheetView(scoreRecord, 5);
	ScoreMinMaxView *minMaxView = new ScoreMinMaxView(scoreRecord);

	scoreRecord->attach(dataSheetView3);
	scoreRecord->attach(dataSheetView5);

	scoreRecord->attach(minMaxView);

	for (int index = 1; index <= 5; index++)
	{
		int score = index * 10;
		cout << "Adding : " << score << endl;
		scoreRecord->addScore(score);
	}


	return 0;

}