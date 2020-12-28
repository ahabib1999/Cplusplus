/* Name: Akbar Habib
Date: 11/08/2020
Section: 0010.fa20
Assignment: 9
Due Date: 11/08/2020
About this project: This menu driven program provides help with bowling games and scores using pointers
Assumptions: (write any assumptions made here (ex: assumes correct user input))
All work below was performed by Akbar Habib */

#include <iostream> // library required for using the cout and cin objects
#include <iomanip> // library required for using the setw function
using namespace std; // namespace for using the cout object

int* AddScore( int* scores, int& NUM_GAMES);
int getValidScore();
void displayAverageScore(int* scores, int numGames);
void displayMenu();
int validateUserInput(int userInput);
int getValidGame(int maxGames);
void displayScores(int* scores, int numGames);
void changeAScore(int* scores, int numGames);
void displayGameHighestScore(int* scores, int numGames);
void displayAverageScore(int* scores, int numGames);

// Function prototypes

int main()
{
	int NUM_GAMES = 3;
	int s[] = { 178,98,288 };
	int* scores = s;
	int userInput;

	// Declaring / Initializing the local variables

	cout << "Welcome to the help with the bowling tournament program!" << endl; // Displaying the welcome message to the user
	displayMenu(); // Function call to display the menu

	cout << "Select an option (1, 2, 3, 4, 5, 6): "; // Prompt displayed asking user to select a menu option
	cin >> userInput; // Saving the user input
	userInput = validateUserInput(userInput); // Function call to validate user input

	while (userInput != 6) // runs while user has not selected the Quit option
	{

		if (userInput == 1) // If user chooses to view scores
		{
			displayScores(scores, NUM_GAMES); // Function call to display games and scores to the user
		}

		else if (userInput == 2) // If user chooses to change a score
		{
			changeAScore(scores, NUM_GAMES); // Function call to allow user to change a score
		}

		else if (userInput == 3) // If user chooses to view the game with the highest score
		{
			displayGameHighestScore(scores, NUM_GAMES); // Function call to display the game with the highest score
		}

		else if (userInput == 4)
		{
			displayAverageScore(scores, NUM_GAMES); // Function call to display the average score
		}

		else if (userInput == 5)
		{
			scores = AddScore(scores, NUM_GAMES); // Function call to add a game
		}

		displayMenu();
		cout << "Select an option (1, 2, 3, 4, 5, 6): ";
		cin >> userInput;
		userInput = validateUserInput(userInput);

		// Displays the menu options again and asks for user to choose an option again
		// And validates the option chosen by the user
	}

	cout << "Thanks for using the program!" << endl;

	// If user chooses to quit, a thank you message is displayed to the user
}

void displayMenu() // Function definiton for displaying the menu options
{
	cout << endl;
	cout << "1) Display the scores" << endl;
	cout << "2) Change a score" << endl;
	cout << "3) Display game with the highest score" << endl;
	cout << "4) Display average game score" << endl;
	cout << "5) Add a score" << endl;
	cout << "6) Quit" << endl;
}

int validateUserInput(int userInput) // Function definition for validating the user input for menu option selection 
{
	while (userInput < 1 || userInput > 6) // Runs while user input is less than 1 or greater than 6 
	{
		cout << endl;
		cout << "You have entered a number less than 1 or greater than 6" << endl; // Error message displayed to the user
		cout << "Please select a valid option (1, 2, 3, 4, 5, 6): "; // Prompt for reentering user input
		cin >> userInput; // Input is saved and checked again
	}
	cout << endl;
	return userInput; // Input is returned back to the function call
}

int getValidGame(int maxGames)
{
	int gameNum;

	cout << "Please enter in the game number..." << endl; // Prompt asking for game number
	cin >> gameNum;

	while (gameNum < 1 || gameNum > maxGames) // While input is out of bounds
	{
		cout << endl;
		cout << "Please enter a valid game number between 1 and " << maxGames << "..." << endl; // Prompt for entering a valid game number
		cin >> gameNum;
	}

	return gameNum; // Game number returned back to the user
}

int* AddScore(int* scores, int& NUM_GAMES)
{
	const int GAMES = 3;
	const int numGames = GAMES + 1;
	int* updScoresArr = new int[NUM_GAMES + 1]; // New array for updated number of games

	// Declaring / Initializing local variables

	for (int i = 0; i < NUM_GAMES; i++)
	{
		updScoresArr[i] = scores[i];
	}

	// Copying scores from old array to new array

	int newScore = getValidScore(); // Getting the new score for the additional game
	updScoresArr[NUM_GAMES] = newScore; // Adding the new score to the array

	NUM_GAMES += 1; // Updating number of games
	//scores = updScoresArr;// Pointer pointing to the new array

	return updScoresArr; // Returning back the pointer
}

void displayScores(int* scores, int numGames) // Function definition for displaying the scores to the user
{
	for (int i = 0; i < numGames; i++) // Loop running for number of games
	{
		cout << setw(10) << "Game " << i + 1; // Displaying game numbers to the user
	}
	cout << endl;

	for (int i = 0; i < numGames; i++)
	{
		cout << setw(10) << scores[i]; // Accessing scores and displaying scores corresponding to each game
	}
	cout << endl;
}

int getValidScore() 
{ // Function definiton for validating the score input given by the user

	int score; // Variable initialization

	cout << "Please enter in the bowling score between 0 and 300..." << endl; // Prompt asking the user to enter a score
	cin >> score; // Input is saved

	while (score < 0 || score > 300) // Runs while input is out of valid bounds 
	{
		cout << endl;
		cout << "Please enter in a valid score between 0 and 300..." << endl; // Prompt asking for valid score
		cin >> score;
	}
	return score; // Score returned back to the function call
}

void changeAScore(int* scores, int numGames) // Function definition for changing a score
{
	int newScore;
	int gameNum;

	gameNum = getValidGame(numGames); // Function call for getting back the game number
	newScore = getValidScore(); // Function for getting back the new score for that game

	scores[gameNum - 1] = newScore; // New score replacing the old for that game in the array
}

void displayGameHighestScore(int* scores, int numGames) // Function definition for displaying game with highest score
{
	int highestScore = -1;
	int highestScoreGame = 0;

	for (int i = 0; i < numGames; i++)
	{
		if (scores[i] > highestScore)
		{
			highestScore = scores[i];
			highestScoreGame = i + 1;
		}
		// Checking and updating the variable to get the highest of the scores from the array and the game associated with that score
	}
	cout << "The game with the highest score is Game " << highestScoreGame << endl; // Displaying the game number with the highest score to the user
}

void displayAverageScore(int* scores, int numGames) // Function definition for displaying the average of all the game scores 
{
	double avgScore;
	double totalScore = 0;

	// Declaration and initialization of local variables

	for (int i = 0; i < numGames; i++)
	{
		totalScore += scores[i]; // Getting the total of all the game scores
	}

	avgScore = totalScore / numGames; // Dividing the total score by number of games to get the average score
	cout << "The average score is..." << endl;
	cout << fixed << setprecision(2) << avgScore << endl; // Displaying the average to the user
}
