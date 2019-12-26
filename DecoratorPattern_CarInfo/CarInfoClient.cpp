#include "CarInfo.h"
using namespace std;

int main( int argc, char* argv[])
{
	CarComponent *car = new BasicCar(100);
	for (int i=1; i< argc; i++ )
	{
		cout << argv[i] << endl;
		if (strcmp(argv[i],"AirBag"))
			car = new AirBagDecorator(car, 200);
		if (strcmp(argv[i], "ESC"))
			car = new ESCDecorator(car, 150);
	}
	
	cout << car->getPrice() << endl;
	cout << car->getString() << endl;

	return 0;
}