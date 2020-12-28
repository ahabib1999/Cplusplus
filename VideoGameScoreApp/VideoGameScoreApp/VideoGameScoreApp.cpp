/* Name: Akbar Habib
Date: 11/28/2020 
Section: 0010.fa20
Assignment: 12 
Due Date: 11/29/2020
About this project: Member function definitons for the video game score class
Assumptions: (write any assumptions made here (ex: assumes correct user input)) 
All work below was performed by Akbar Habib */

#include <iostream>			// Required for using cout object
#include "VideoGameScore.h" // header file containing the class
#include <string>			// required for using string class
using namespace std;		// namespace required for using cout object

void displayScoreObject(VideoGameScore scoreObj);

// Function prototype

int main()
{
	VideoGameScore score1, score2, score3;

	// Declaring local variables

	score1.setName("Lucy Smith");
	score1.setScore(200);

	score2.setName("Jeff Bridges");
	score2.setScore(12000);

	score3.setName("Ben James");
	score3.setScore(50000);

	// Setting the attributes for all the instances of the VideoGameScore class

	displayScoreObject(score1); // Function call to display the contents of the first object
	displayScoreObject(score2); // Function call to display the contents of the second object
	displayScoreObject(score3); // Function call to display the contents of the third object
}

void displayScoreObject(VideoGameScore scoreObj) // Function definiton for displaying the contents of the score object
{
	bool isAboveTenThousand;

	// Declaring local variable

	cout << "Name: ";
	cout << scoreObj.getName() << endl;

	// Displaying the name

	cout << "Score: ";
	cout << scoreObj.getScore() << endl;

	// Displaying the score

	cout << "Score Above Ten Thousand?: ";

	isAboveTenThousand = scoreObj.aboveTenThousand(scoreObj.getScore());

	// Function call to determine whether score is above ten thousand

	if (isAboveTenThousand == true) // If score is above ten thousand
	{
		cout << "Yes" << endl;
		cout << endl;
	}

	else // If the score is not above ten thousand
	{
		cout << "No" << endl;
		cout << endl;
	}
}
