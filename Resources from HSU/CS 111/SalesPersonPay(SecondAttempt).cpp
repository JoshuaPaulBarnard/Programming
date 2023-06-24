//------------------------------------------------------------------------------
// Joshua P. Barnard
// CS 111 HW
// Due: 10/31/13
// Sales Person Weekly Pay
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

//******************************************************************************
//function for determining highest pay
//******************************************************************************

float total(float salary, float rate, float sales)
{
		float commission;
		rate = rate * 0.01;
		
		commission = sales * rate;
		
		if(commission > salary)
			return commission;
		
		if(salary > commission)
			return salary;
		
}

//******************************************************************************
// Main program for inputing variables and outputting responce
//******************************************************************************

int main()
{
	
	float salary, rate, sales, pay;
	
	cout.setf(ios::fixed);
	cout.precision(2);
	
	cout<<"Person's Salary: $";
	cin>>salary;
	
	
	while(salary != 0)
	{
		
		cout<<"Person's Commission Rate (%): ";
		cin>>rate;
	
		cout<<"Person's Total Sales: $";
		cin>>sales;
		
		pay = total(salary,rate,sales);
		
		cout<<"Person's Weekly Pay Is:  $"<<pay<<'\n'<<'\n';
		
		cout<<"Person's Salary: $";
		cin>>salary;
		
		
	}
	
	return 0;
}
