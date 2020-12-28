/* Name: Akbar Habib 
Date: 11/14/2020
Section: 0010.fa20
Assignment: 10
Due Date: 11/15/2020
About this project: Displays data about the passengers on board the titanic reading it from an external file
Assumptions: (write any assumptions made here (ex: assumes correct user input)) 
All work below was performed by Akbar Habib */


#include <iostream>
#include <fstream> // required for file input and output
#include <vector> // required for using vectors
#include <string> // required for working with strings
#include <iomanip> // required for formatting output
using namespace std; // namespace used for cout

void readFromFile(vector<int> &Age, vector<string> &PassengerClass, vector<bool> &Survived);
void displayAliveAndDeadCount(vector <bool> Survived);
void displaySurvivedByPassengerClass(vector <string> PassengerClass, vector <bool> Survived);
void displayMenu();
char getValidUserInput();

// function prototypes

int main()
{   
    vector<int> Age;
    vector<string> PassengerClass;
    vector<bool> Survived;
    char userInput;

    // variables declared and / or initialized

    cout << "Welcome to the titanic data program";
    cout << endl;

    // Display welcome message to the user

    displayMenu(); // Function call to display the menu
    userInput = getValidUserInput(); // Function call to get the user input
    readFromFile(Age, PassengerClass, Survived); // Function call to read data from file

    if (userInput == 'A') { // if user enters A
        displayAliveAndDeadCount(Survived); // Function call to display number of survivors and deaths
    }

    else { // if user enters B
        displaySurvivedByPassengerClass(PassengerClass, Survived); // Function call to display number of survivors by passenger class
    }

    cout << "Thanks for using the program!" << endl; // Display thank you message to the user
}

void displayMenu() { // Function definiton for displaying menu

    cout << endl;
    cout << "A) Display count of people who lived and died" << endl;
    cout << "B) Display count of people who lived by Passenger Class" << endl;
}

char getValidUserInput() { // Function definiton for getting valid user input

    char userInput;

    cout << endl;
    cout << "Please select option (A-B)... "; // Prompt asking user to choose option
    cin >> userInput; // saving the input
    userInput = toupper(userInput); // Converting input to upper case

    while (userInput != 'A' && userInput != 'B') { // checking for invalid input

        cout << endl;
        cout << "You have entered invalid input" << endl; // Display error message
        cout << "Please choose option A or B... "; // Prompt for reentering input 
        cin >> userInput;
        userInput = toupper(userInput);
    }
    cout << endl;
    return userInput; // returning the valid user input to the main function
}

void readFromFile(vector<int> &Age, vector<string> &PassengerClass, vector<bool> &Survived)
{ // Function definition for reading data from the file
    string ageNum, passengerClass, aliveStatus; // declaring variables
    ifstream inputFile; // Stream object for opening and reading a file
    inputFile.open("TitanicData.txt"); // opening the data file

    while (inputFile >> ageNum >> passengerClass >> aliveStatus) { // runs while there is data to be read in file

        int intAge = stoi(ageNum); // saves the int value of the string variable
        Age.push_back(intAge); // adds the age to the Age vector

        PassengerClass.push_back(passengerClass); // Adds the class name to the Passenger Class vector

        if (aliveStatus == "TRUE") // If passenger survived
        {
            Survived.push_back(true); // add boolean value true to the Survived vector
        }

        else // If passenger died
        {
            Survived.push_back(false); // Add boolean value false to the vector
        }
    }
}

void displayAliveAndDeadCount(vector <bool> Survived) // Function definition for displaying survivors and deaths
{
    int aliveCount = 0;
    int deathCount = 0;
    double alivePercent = 0;
    double deathPercent = 0;
    double numPeople = 0;

    // Initializing local variables

    for (int i = 0; i < Survived.size(); i++)
    {
        if (Survived[i] == true) // If passenger survived
        {
            aliveCount += 1; // Increment aliveCount by 1
        }
        
        else // if passenger died
        {
            deathCount += 1; // Increment deathCount by 1
        }
        numPeople += 1; // Increment number of people for each iteration
    }

    alivePercent = aliveCount / numPeople; // Getting the percentage of survivors
    deathPercent = deathCount / numPeople; // Getting the percentage of deaths

    cout << endl;
    cout << "Number of passengers who lived: ";
    cout << aliveCount << endl;

    // Displaying the number of survivors

    cout << "Number of people who died: ";
    cout << deathCount << endl;

    // Displaying the number of deaths

    cout << "Percentage of people who lived: ";
    cout << fixed << setprecision(4) << alivePercent << endl;

    // Displaying the percentage of survivors

    cout << "Percentage of people who died: ";
    cout << fixed << setprecision(4) << deathPercent << endl;

    // Displaying the percentage of deaths
}

void displaySurvivedByPassengerClass(vector <string> PassengerClass, vector <bool> Survived)
{ // Function definition for displaying number of survivors for each class
    int firstClassCount = 0;
    int secondClassCount = 0;
    int thirdClassCount = 0;
    int alaCarteCount = 0;
    int deckCount = 0;
    int engineCount = 0;
    int victuallingCount = 0;

    // Initializing local variables

    for (int i = 0; i < PassengerClass.size(); i++)
    {
        if (Survived[i] == true) // If passenger survived
        {
            if (PassengerClass[i] == "1stClass") // If passenger was in 1st Class
            {
                firstClassCount += 1;
            }

            else if (PassengerClass[i] == "2ndClass") // If passenger was in 2nd Class
            {
                secondClassCount += 1;
            }

            else if (PassengerClass[i] == "3rdClass") // If passenger was in 3rd class
            {
                thirdClassCount += 1;
            }

            else if (PassengerClass[i] == "AlaCarte") // if passenger was in AlaCarte 
            {
                alaCarteCount += 1;
            }

            else if (PassengerClass[i] == "Deck") // if passenger was on Deck
            {
                deckCount += 1;
            }

            else if (PassengerClass[i] == "Engine") // if passenger was in Engine
            {
                engineCount += 1;
            }

            else { // if passenger was in Victualling
                victuallingCount += 1;
            }
        }  
    }

    cout << endl;
    cout << "Number of people who lived by class" << endl;
    cout << endl;
    cout << setw(30) << "Class" << setw(30) << "Number" << endl;

    cout << setw(30) << "1stClass" << setw(30) << firstClassCount << endl;
    cout << setw(30) << "2ndClass" << setw(30) << secondClassCount << endl;
    cout << setw(30) << "3rdClass" << setw(30) << thirdClassCount << endl;
    cout << setw(30) << "AlaCarte" << setw(30) << alaCarteCount << endl;
    cout << setw(30) << "Deck" << setw(30) << deckCount << endl;
    cout << setw(30) << "Engine" << setw(30) << engineCount << endl;
    cout << setw(30) << "Victualling" << setw(30) << victuallingCount << endl;

    // Displaying the number of survivors for every passenger class
}

