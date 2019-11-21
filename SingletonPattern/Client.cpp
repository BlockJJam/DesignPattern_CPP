#include "Printer.h"

using namespace std;

int main()
{
	FakePrinter fake_printer ;
	UsePrinter user_printer;
	RealPrinter99 real;

	user_printer.doSomething(fake_printer);

	cout << fake_printer.get() << endl;

	return 0;
}