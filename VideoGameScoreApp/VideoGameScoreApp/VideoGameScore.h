/* Name: Akbar Habib
Date: 11/28/2020 
Section: 0010.fa20
Assignment: 12 
Due Date: 11/29/2020
About this project: Header file for the video game score class
Assumptions: (write any assumptions made here (ex: assumes correct user input)) 
All work below was performed by Akbar Habib */

#ifndef VideoGameScore_H
#define VideoGameScore_H
#include <string>

// Including required libraries and headers

using namespace std; // namespace for using cout object

class VideoGameScore // Declaration of the VideoGameScore class
{
private:
	string Name;
	double Score;

	// Private member variables of the class

public:
	string getName();
	double getScore();
	void setName(string name);
	void setScore(double score);
	VideoGameScore();
	VideoGameScore(string name);
	bool aboveTenThousand(double score);

	// Public member functions of the class
};

#endif
