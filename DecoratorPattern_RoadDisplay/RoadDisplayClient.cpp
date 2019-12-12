#include "RoadDisplay.h"

void main()
{
	Display *road = new RoadDisplay();
	road->draw();

	Display *roadWithLane = new LaneDecorator(new RoadDisplay());
	roadWithLane->draw();

	Display *roadWithLaneTraffic = new TrafficDecorator(new LaneDecorator(new RoadDisplay()));
	roadWithLaneTraffic->draw();
}