#include "Robot.h"

using namespace std;

int main()
{

	FlyingStrategy	flying;
	WalkingStrategy walking;
	MissileStrategy missile;
	PunchStrategy	punch;;

	Robot atom = Atom("Atom");
	Robot taekwonV = TaekwonV("TaekwonV");

	atom.setMovingStrategy(new FlyingStrategy());
	atom.setAttackingStrategy(new MissileStrategy());
	
	taekwonV.setMovingStrategy(new WalkingStrategy());
	taekwonV.setAttackingStrategy(new PunchStrategy());

	cout << " my name is : " << atom.getName() << endl;
	atom.move();
	atom.attack();

	cout << " my name is : " << taekwonV.getName() << endl;
	atom.move();
	atom.attack();

	return 0;

}