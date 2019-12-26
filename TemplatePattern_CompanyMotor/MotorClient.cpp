#include "Motor.h"

using namespace std;

int main()
{
	Door door;

	Motor *hyundaiMotor = new HyundaiMotor(door);
	Motor *lgMotor = new LGMotor(door);

	hyundaiMotor->move(Direction::UP);
	hyundaiMotor->move(Direction::DOWN);
	lgMotor->move(Direction::DOWN);


	return 0;
}