

#include <iostream>

// Library required for input and output of data

#include <iomanip>

// Library for formatting the output

#include <cstdlib>

// Library required for using srand and rand functions

#include <ctime>

// Library required for getting the current time

#include <vector>

// Library required for using vectors



using namespace std;

int Get_Num_Of_Balls();
int Validate_User_Input(int userinput, int lowerbound, int upperbound);
int Get_Largest_Num_In_Lottery();
int Get_Num_Of_Tickets();
long int Calculate_Odds_Of_Winning(int numofballs, int largestnum);
void Get_Lottery_Ticket_Nums(int largestnum, int numofballs, vector <int> lotteryticket);
bool Is_Num_Duplicate(vector <int> lotteryticket, int randomnumber);
void Display_Lottery_Numbers();

// Function Prototypes

// *****************************************************************
// * Function Name: main *
// * Description: Start of the program, calls the required functions *
// * Parameter Description: N/A *
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int main()
{
	cout << "Welcome to the lottery ticket numbers generator";
	cout << endl;

	// Displaying welcome message to the user

	srand(time(0));

	// Seeding data to the rand function

	Display_Lottery_Numbers();

	// Function call to display lottery ticket numbers

	cout << endl;
	cout << "Thanks for using the program";
}

// *****************************************************************
// * Function Name: Calculate_Odds_Of_Winning *
// * Description: Calculates the odds of winning for the user based *
// * on the number of balls and the largest number * 
// * Parameter Description: 
// * numofballs, type = int, used to reference the number of balls *
// * largestnum, type = int, used to reference the largest number for the tickets *
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

long int Calculate_Odds_Of_Winning(int numofballs, int largestnum)
{
	long long numerator = 1;
	int denominator = 1;
	long int odds;

	
	for (int i = 1; i <= numofballs; i++)
	{
		numerator *= largestnum;
		largestnum--;
		denominator *= i;
	}
	odds = numerator / denominator;

	return odds;
}

// *****************************************************************
// * Function Name: Get_Num_Of_Balls *
// * Description: Gets the number of balls per ticket *
// * Parameter Description: N/A *
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Get_Num_Of_Balls()
{
	int numofballs;
	const int NUMBALLSLOWERBOUND = 3;
	const int NUMBALLSUPPERBOUND = 7;

	cout << endl;
	cout << "Enter in the number of balls or numbers you wish to pick from." << endl;
	cout << "The number must be between " << NUMBALLSLOWERBOUND << " and " << NUMBALLSUPPERBOUND << ": ";
	cin >> numofballs;

	numofballs = Validate_User_Input(numofballs, NUMBALLSLOWERBOUND, NUMBALLSUPPERBOUND);

	return numofballs;
}

// *****************************************************************
// * Function Name: Get_Num_Of_Balls *
// * Description: Gets the largest number that any ticket can have *
// * Parameter Description: N/A *
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Get_Largest_Num_In_Lottery()
{
	int largestnum;
	const int LARGESTNUMLOWERBOUND = 45;
	const int LARGESTNUMUPPERBOUND = 70;

	cout << endl;
	cout << "Enter in the largest number in the lottery." << endl;
	cout << "The number must be between " << LARGESTNUMLOWERBOUND << " and " << LARGESTNUMUPPERBOUND << ": ";
	cin >> largestnum;

	largestnum = Validate_User_Input(largestnum, LARGESTNUMLOWERBOUND, LARGESTNUMUPPERBOUND);
	return largestnum;
}

// *****************************************************************
// * Function Name: Get_Num_Of_Tickets *
// * Description: Gets the number of lottery tickets *
// * Parameter Description: N/A *
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Get_Num_Of_Tickets()
{
	int numtickets;
	const int NUMTICKETSLOWERBOUND = 1;
	const int NUMTICKETSUPPERBOUND = 100;

	cout << endl;
	cout << "Enter the number of tickets." << endl;
	cout << "The number must be between " << NUMTICKETSLOWERBOUND << " and " << NUMTICKETSUPPERBOUND << ": ";
	cin >> numtickets;

	numtickets = Validate_User_Input(numtickets, NUMTICKETSLOWERBOUND, NUMTICKETSUPPERBOUND);
	return numtickets;
}

// *****************************************************************
// * Function Name: Get_Lottery_Ticket_Nums *
// * Description: Gets and Displays the lottery numbers of a lottery ticket *
// * while checking for duplicate values *
// * Parameter Description: *
// * numofballs, type = int, used to reference the number of balls *
// * largestnum, type = int, used to reference the largest number for the tickets *
// * lotteryticket = type = vector<int>, referencing the vector that stores the lottery numbers
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Get_Lottery_Ticket_Nums(int largestnum, int numofballs, vector<int> lotteryticket)
{
	int randomnumber;
	bool isduplicate;

	for (int j = 0; j < numofballs; j++)
	{
		isduplicate = true;

		while (isduplicate)
		{
			randomnumber = rand() % largestnum + 1;
			isduplicate = Is_Num_Duplicate(lotteryticket, randomnumber);
		}

		lotteryticket.push_back(randomnumber);
		cout << randomnumber << " ";
	}
}

// *****************************************************************
// * Function Name: Display_Lottery_Numbers *
// * Description: Calls functions to get the required values *
// * and runs a loop to get the lottery numbers for each ticket *
// * Parameter Description: N/A *
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Display_Lottery_Numbers()
{
	int numofballs;
	int largestnum;
	int numtickets;
	vector <int> lotteryticket;
	long int odds;

	numofballs = Get_Num_Of_Balls();

	largestnum = Get_Largest_Num_In_Lottery();

	numtickets = Get_Num_Of_Tickets();

	odds = Calculate_Odds_Of_Winning(numofballs, largestnum);

	cout << endl;
	cout << "You will select " << numofballs << " numbers" << endl;
	cout << "The numbers will range from 1 to " << largestnum << endl;
	cout << "The odds are 1 in " << odds << endl;

	for (int i = 0; i < numtickets; i++)
	{
		cout << endl;
		Get_Lottery_Ticket_Nums(largestnum, numofballs, lotteryticket);
		lotteryticket.clear();
	}
}

// *****************************************************************
// * Function Name: Is_Num_Duplicate *
// * Description: Checks whether the lottery numbers are duplicate *
// * and prompts the generation of a new number if they are *
// * Parameter Description: *
// * lotteryticket = type = vector<int>, referencing the vector that stores the lottery numbers *
// * randomnumber = type = int, references the random number that gets generated for the lottery ticket *
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

bool Is_Num_Duplicate(vector <int> lotteryticket, int randomnumber)
{
	for (int i = 0; i < lotteryticket.size(); i++)
	{
		if (lotteryticket.at(i) == randomnumber)
		{
			return true;
		}
	}
	return false;
}

// *****************************************************************
// * Function Name: Validate_User_Input *
// * Description: Validates the user input to check if it is within bounds *
// * and prompts the input of a new number if it is *
// * Parameter Description: *
// * userinput = type = int, references the user input *
// * lowerbound = type = int, references the lower bound for the validation of the input *
// * upperbound = type = int, references the upper bound for the validation of the input *
// * Date: 01/12/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Validate_User_Input(int userinput, int lowerbound, int upperbound)
{
	while (userinput < lowerbound || userinput > upperbound)
	{
		if (userinput < lowerbound)
		{
			cout << "You have entered a number less than " << lowerbound << endl;
		}

		else if (userinput > upperbound)
		{
			cout << "You have entered a number greater than " << upperbound << endl;
		}

		cout << "Please enter a number between " << lowerbound << " and " << upperbound << ": ";
		cin >> userinput;
	}
	return userinput;
}
