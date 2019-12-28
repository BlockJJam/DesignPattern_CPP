#include "ElevatorManager.h"
using namespace std;

int main()
{
	ElevatorManager *manager = new ElevatorManagerWithThroughputScheduling(3);

	manager->requestElevator(3, Direction::UP);

	return 0;
}