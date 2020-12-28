/* Name: Akbar Habib 
Date: 10/20/2020 
Section: 0010.fa20
Assignment: 8 
Due Date: 10/25/2020
About this project: This menu driven program provides help with bowling games and scores
Assumptions: (write any assumptions made here (ex: assumes correct user input)) 
All work below was performed by Akbar Habib */

#include <iostream> // library required for using the cout and cin objects
#include <iomanip> // library required for using the setw function
using namespace std; // namespace for using the cout object

int getValidScore();
int getValidGame(int maxGames);
void displayScores(int scores[], int numGames);
void changeAScore(int scores[], int numGames);
void displayMenu();
int validateUserInput(int userInput);
void displayGameHighestScore(int scores[], int numGames);
void displayAverageScore(int scores[], int numGames);
void displaySortedScores(int scores[]);

// Function prototypes


int main()
{
	const int NUM_GAMES = 3;
	int scores[NUM_GAMES] = { 178,98,288 };
	int userInput;

	// Declaring and/or initializing local variables

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
			displayAverageScore(scores, NUM_GAMES);
		}

		else if (userInput == 5)
		{
			displaySortedScores(scores);
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
	cout << "5) Display a sorted list of the scores" << endl;
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

int getValidScore() { // Function definiton for validating the score input given by the user

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

int getValidGame (int maxGames)
{
	int gameNum;

	cout << "Please enter in the game number (1, 2, 3)..." << endl; // Prompt asking for game number
	cin >> gameNum;

	while (gameNum < 1 || gameNum > maxGames) // While input is out of bounds
	{
		cout << endl;
		cout << "Please enter a valid game number between 1 and " << maxGames << "..." << endl; // Prompt for entering a valid game number
		cin >> gameNum;
	}

	return gameNum; // Game number returned back to the user
}

void displayScores (int scores[], int numGames) // Function definition for displaying the scores to the user
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

void changeAScore(int scores[], int numGames) // Function definition for changing a score
{
	int newScore;
	int gameNum;

	gameNum = getValidGame(numGames); // Function call for getting back the game number
	newScore = getValidScore(); // Function for getting back the new score for that game

	scores[gameNum - 1] = newScore; // New score replacing the old for that game in the array
}

void displayGameHighestScore(int scores[], int numGames) // Function definition for displaying game with highest score
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

void displayAverageScore(int scores[], int numGames) // Function definition for displaying the average of all the game scores 
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

void displaySortedScores(int scores[]) // Function definition for displaying sorted game scores 
{
	const int NUM_GAMES = 3;
	int gameScores[NUM_GAMES];
	bool madeASwap;

	// Declaration and initialization of local variables

	for (int i = 0; i < NUM_GAMES; i++)
	{
		gameScores[i] = scores[i]; // copying the scores into the new array
	}

	for (int i = 0; i < NUM_GAMES; i++)
	{
		for (int j = i; j < NUM_GAMES; j++)
		{
			if (i == j) // if it is the same same element
			{
				continue; // skip over it
			}

			if (gameScores[j] > gameScores[i]) // if a larger number is found than the current number
			{
				int temp = gameScores[j]; // temp variable for storing one of the numbers
				gameScores[j] = gameScores[i]; // the smaller number pushed down the array
				gameScores[i] = temp; // the larger number saved in the current index
			}
		}
	}

	cout << "Sorted list of scores" << endl;

	for (int i = 0; i < NUM_GAMES; i++)
	{
		cout << gameScores[i] << " "; // Displaying the sorted list of numbers by looping over the new and sorted array
	}
	cout << endl;
}
