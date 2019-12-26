#include "ReportGenerator.h" 
using namespace std;

int main()
{
	vector<Customer> customers;
	customers.push_back(Customer("ȫ�浿", 150));
	customers.push_back(Customer("�����", 90));
	customers.push_back(Customer("�ȳ�?", 20));
	customers.push_back(Customer("greg", 111));

	ReportGenerator *simpleGenerator = new SimpleReportGenerator();
	cout << simpleGenerator->generate(customers) << endl;

	cout << endl << endl;

	ReportGenerator *complexGenerator = new ComplexReportGenerator();
	cout << complexGenerator->generate(customers) << endl;

	return 0;
}