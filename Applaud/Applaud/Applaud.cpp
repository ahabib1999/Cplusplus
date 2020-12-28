/* 
Name: Akbar Habib 
Date: 09/15/2020 
Section: 0010.fa20
Assignment: Assignment 4 
Due Date: 09/20/2020
About this project: This program gives different prompts to the user and, using decision structures, asks follow up questions depending on user's path 
Assumptions: (write any assumptions made here (ex: assumes correct user input)) 
All work below was performed by Akbar Habib 
*/

#include <iostream> // required for inputing and outputing data

using namespace std; // namespace for using cout

int main() // starting of main function
{
	char userAns; // variable to hold user input
	cout << "Welcome to the Should I Applaud program" << endl; // displays welcome message to the user

	cout << "Do you know how the piece ends ? (Y/N) "; // Asks the first question
	cin >> userAns;	// assigns the input to the variable

	if (isdigit(userAns))
	{
		cout << "You entered a digit, which is an invalid input." << endl;
		cout << "Please enter a single letter. (Y/N) " << endl;
		cin >> userAns;
	}
	// Validates the input to make sure it is not a digit
	// if it is, prints an error message to the user
	// and asks to input again
	userAns = toupper(userAns); // changes the input to the upper case

	if (userAns != 'Y' && userAns != 'N')
	{
		cout << "You have entered an incorrect letter" << endl;
		cout << "Please enter 'Y' or 'y' for yes" << endl;
		cout << "Or enter 'N' or 'n' for no ";
		cin >> userAns;
		userAns = toupper(userAns);
	}
	// Validates the input to make sure it is no letter apart from 'Y' or 'N'
	// if it is incorrect, prints an error message and asks for input again

	else if (userAns == 'Y')
	{ // user knows how the piece ends

		cout << "Was that the end of the piece ? (Y/N) "; // asks the follow up question on the path
		cin >> userAns;	// uses the same variable to hold the input

		if (isdigit(userAns))
		{
			cout << "You entered a digit, which is an invalid input." << endl;
			cout << "Please enter a single letter. (Y/N) ";
			cin >> userAns;
		}
		userAns = toupper(userAns);

		if (userAns != 'Y' && userAns != 'N')
		{
			cout << "You have entered an incorrect letter" << endl;
			cout << "Please enter 'Y' or 'y' for yes" << endl;
			cout << "Or enter 'N' or 'n' for no ";
			cin >> userAns;
			userAns = toupper(userAns);
		}

		else if (userAns == 'Y')
		{	// That was the end of the piece
			cout << "Go Ahead" << endl; // Ending message for the path. Program ends
		}

		else
		{	// Not the end of the piece
			cout << "Probably Not" << endl; // Ending message for the path. Program ends
		}
	}

	else
	{	// user does not know how the piece ends
		cout << "Is the performer about to bow ? (Y/N) "; // asks the follow up question
		cin >> userAns;	// saves the input

		if (isdigit(userAns))
		{
			cout << "You entered a digit, which is an invalid input." << endl;
			cout << "Please enter a single letter. (Y/N) ";
			cin >> userAns;
		}
		userAns = toupper(userAns);

		if (userAns != 'Y' && userAns != 'N')
		{
			cout << "You have entered an incorrect letter" << endl;
			cout << "Please enter 'Y' or 'y' for yes" << endl;
			cout << "Or enter 'N' or 'n' for no ";
			cin >> userAns;
			userAns = toupper(userAns);
		}

		else if (userAns == 'Y')
		{	// performer is about to bow
			cout << "Go Ahead" << endl; // ending message for the path. Program ends
		}

		else
		{ // performer is not about to bow

			cout << "Is everybody else applauding ? (Y/N) "; // asksthe follow up question
			cin >> userAns;

			if (isdigit(userAns))
			{
				cout << "You entered a digit, which is an invalid input." << endl;
				cout << "Please enter a single letter. (Y/N) ";
				cin >> userAns;
			}
			userAns = toupper(userAns);

			if (userAns != 'Y' && userAns != 'N')
			{
				cout << "You have entered an incorrect letter" << endl;
				cout << "Please enter 'Y' or 'y' for yes" << endl;
				cout << "Or enter 'N' or 'n' for no ";
				cin >> userAns;
				userAns = toupper(userAns);
			}

			else if (userAns == 'Y')
			{	// everybody else is applauding
				cout << "Go Ahead" << endl; // ending message for the path. Program ends.
			}

			else
			{ // no one is applauding
				cout << "Don't start it" << endl; // ending message for the path. Program ends
			}
		}
	} // end of main function
}
