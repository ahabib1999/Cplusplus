#include <iostream>
#include "date.h"
#include <string>

int main()
{

	bool status = false;
	int comparestatus = 0;

	Date date1; // Test Default constructor
	Date date2(2, 29, 2000); // Test 3 param constructor with valid date
	Date date3(15, 15, 1500); // Test 3 param constructor with invalid date
	status = date3.Set(2, 18, 1955); // Test Set method
	cout << status << endl;
	status = date2.SetFormat('T'); // Test SetFormat method
	cout << status << endl;
	date2.Show(); // Test Show method
	date2.Input(); // Test the Input method
	// *******************************************************************************
	// * Test the GetMonth, GetDay, GetYear methods *
	// *******************************************************************************

	cout << date2.GetMonth() << '/' << date2.GetDay() << '/' << date2.GetYear() << endl;
	date1.Increment(); // Test Increment with no parameters
	date1.Increment(5); // Test Increment with one parameter
	comparestatus = date1.Compare(date2); // Test Compare method
	cout << comparestatus << endl;
	return 0;
}