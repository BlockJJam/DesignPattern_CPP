#include "VendingMachine.h"

int main()
{
	VendingMachine * machine = new VendingMachine(5, 1000);

	machine->insertMoney(1000);
	machine->insertMoney(500);
	machine->pushButton();
	machine->returnMoney();
	machine->insertMoney(1000);
	machine->insertMoney(1000);
	machine->pushButton();
	machine->pushButton();
	machine->pushButton();
	machine->returnMoney();


	return 0;
}