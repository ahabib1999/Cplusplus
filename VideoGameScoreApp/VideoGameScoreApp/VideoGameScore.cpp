/* Name: Akbar Habib
Date: 11/28/2020 
Section: 0010.fa20
Assignment: 12 
Due Date: 11/29/2020
About this project: Displays the attributes of different instances of a video game score class
Assumptions: (write any assumptions made here (ex: assumes correct user input)) 
All work below was performed by Akbar Habib */

#include <iostream>			// Required for using cout object
#include "VideoGameScore.h" // Header file containing the class declaration
#include <string>			// Required for using the string class
using namespace std;		// Namespace used for the cout object

VideoGameScore::VideoGameScore() // Default constructor for the VideoGameScore class
{
	Name = "";
	Score = 0;
}

VideoGameScore::VideoGameScore(string name) // Constructor for the VideoGameScore class
{
	Name = name;
	Score = 0;
}

string VideoGameScore::getName() // Accessor method for the Name attribute of the class
{
	return Name; // return Name back to the function call
}

double VideoGameScore::getScore() // Acessor method for the Score attribute
{
	return Score; // returning the Score back to the function call
}

void VideoGameScore::setName(string name) // Mutator method for the Name attribute
{
	Name = name;
}

void VideoGameScore::setScore(double score) // Mutator method for the Score attribute
{
	Score = score;
}

bool VideoGameScore::aboveTenThousand(double score) // Function definiton for determining whether the score is above ten thousand
{
	if (score >= 10000) // If the score is above ten thousand
	{
		return true;
	}

	else // If the score is not above ten thousand
	{
		return false;
	}
}
