#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Customer
{
private:
	string _name;
	int _point;

public:
	Customer(string name, int point)
	{
		_name = name;
		_point = point;
	}

	int getPoint() const
	{
		return _point;
	}
	void setPoint(int point)
	{
		_point = point;
	}

	string getName() const
	{
		return _name;
	}
	void setName(string name)
	{
		_name = name;
	}
};

class ReportGenerator
{
public:
	string generate(vector<Customer> customers)
	{
		vector<Customer> selectedCustomers = select(customers);
		string report = getReportHeader(selectedCustomers);

		for (int i = 0; i < selectedCustomers.size(); i++)
		{
			Customer customer = selectedCustomers[i];
			report += getReportForCustomer(customer);
		}
		report += getReportFooter(selectedCustomers);

		return report;
	}

protected:
	vector<Customer> select(vector<Customer> customers)
	{
		vector<Customer> selected ;
		for (Customer customer : customers)
		{
			if (customerReportCondition(customer))
				selected.push_back(customer);
		}
		return selected;
	}
	
	virtual bool customerReportCondition(Customer customer)  = 0;
	virtual string getReportHeader(vector<Customer> customers) const = 0;
	virtual string getReportForCustomer(Customer customer) const = 0;
	virtual string getReportFooter(vector<Customer> customers) const = 0;
};

class SimpleReportGenerator : public ReportGenerator
{
protected:
	bool customerReportCondition(Customer customer) override
	{
		return true;
	}

	string getReportHeader(vector<Customer> customers) const override
	{
		return "�� �� : " + to_string(customers.size()) + "��\n";
	}

	string getReportForCustomer(Customer customer) const override
	{
		return customer.getName() + " : " + to_string(customer.getPoint()) + "��\n";
	}

	string getReportFooter(vector<Customer> customers) const override
	{
		return "";
	}
};


class ComplexReportGenerator :public ReportGenerator
{
protected:
	bool customerReportCondition(Customer customer) override
	{
		return (customer.getPoint() >= 100);
	}

	string getReportHeader(vector<Customer> customers) const override
	{
		return "�� �� : " + to_string(customers.size()) + "���Դϴ�. \n";
	}

	string getReportForCustomer(Customer customer) const override
	{
		return to_string(customer.getPoint()) + " : " + customer.getName() + "��\n";
	}

	string getReportFooter(vector<Customer> customers)  const override
	{
		int totalPoint = 0;
		for (Customer customer : customers)
		{
			totalPoint += customer.getPoint();
		}
		return "����: " + to_string(totalPoint);
	}

};