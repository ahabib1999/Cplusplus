/* Name: Akbar Habib 
Date: 09/27/2020 
Section: 0010.fa20
Assignment: 5 
Due Date: 09/27/2020
About this project: Asks the user a certain number and runs the pi calculation for that many iterations
Assumptions: user will not enter characters when asked for a number 
All work below was performed by Akbar Habib */

#include <iostream>
#include <iomanip>
using namespace std;
// including the required libraries and identifying the namespace used

int main()
{
	cout << "Welcome to the Pi calculating program" << endl; // Displaying the welcome message

	char runAgain = 'Y';
	int userInput;
	long double piValue;
	// Variables declared and/or initialized

	while (runAgain == 'Y') // runs while runAgain is true
	{
		cout << "Please enter a number greater than 0 "; // Prompt to the user
		cin >> userInput;								 // user's input is saved

		while (userInput <= 0)
		{
			cout << "You have entered a number less than or equal to 0" << endl;
			cout << "Please enter a number greater than 0 ";
			cin >> userInput;
		}
		// input validation to check for user not entering digits or entering an invalid number

		double denominator = 1;
		long double seriesSum = 0;
		double seriesNum;

		for (int i = 0; i <= userInput; i++) // loops until the number entered by the user
		{
			seriesNum = 1 / denominator; // calculates the individual number for the series

			if (i % 2 == 0) // if current index is even
			{
				seriesSum += seriesNum; // number is added to the sum
			}

			else // if current index is odd
			{
				seriesSum -= seriesNum; // number is subtracted from the sum
			}

			denominator += 2; // denominator is incrememnted by 2
		}

		piValue = 4 * seriesSum;							   // pi value is calculated
		cout << fixed << setprecision(250) << piValue << endl; // pi value is displayed to the user

		cout << "Would you like to run the program again ?" << endl;
		// prompt to ask user
		//if they want to run the program again
		cout << "Enter a 'Y' or 'y' for yes and 'N' or 'n' for no ";
		cin >> runAgain;
		runAgain = toupper(runAgain);

		while (isdigit(runAgain) || runAgain != 'Y' && runAgain != 'N')
		// checking for invalid input
		{
			if (isdigit(runAgain))
			{
				cout << "You have entered a digit." << endl;
				cout << "Please enter 'Y' or 'y' for yes and 'N' or 'n' for no ";
				cin >> runAgain;
				runAgain = toupper(runAgain);
			}

			else
			{
				cout << "You have entered a wrong letter." << endl;
				cout << "Please enter 'Y' or 'y' for yes and 'N' or 'n' for no ";
				cin >> runAgain;
				runAgain = toupper(runAgain);
			}
		}
	}

	return 0;
}
