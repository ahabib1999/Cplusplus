/* Name: Akbar Habib 
Date: 09/09/2020 
Section: 0010.fa20
Assignment: Assignment 3 
Due Date: 09/13/2020
About this project: This program takes required input from the user and calculates the temperature of an object at a certain time
Assumptions: Correct user input 
All work below was performed by Akbar Habib */


#define _USE_MATH_DEFINES // macro required to include mathematical constants
#include <iostream> // required for input and output of data
#include <cmath> // required for using different mathematical functions and constants
#include <iomanip> // required for using stream manipulators
using namespace std;

int main()
{
    double time, currentTemp, initTemp, coolingConstant; // Declaration of the variables

    cout << "Welcome to the Law of Cooling program"; // Displaying the welcome message

    cout << "Please enter the time (in seconds): "; 
    cin >> time;

    cout << "Please enter the surrounding temperature (in Kelvin): ";
    cin >> currentTemp;

    cout << "Please enter the initial temperature (in Kelvin): ";
    cin >> initTemp;

    cout << "Please enter the cooling constant, specific to the object (1/seconds): ";
    cin >> coolingConstant;

    // Displaying prompts to the user and getting inputs
    // Assigning the inputs to the appropriate variables

    double power = coolingConstant * time * -1; // getting the exponent for the M_E
    double tempDiff = initTemp - currentTemp; // getting the temp difference for the equation
    double tempAtDesiredTime = currentTemp + tempDiff * pow(M_E, power); // calculating the temp for a certain time using the given inputs

    cout << fixed << showpoint << setprecision(5); // formatting the output to show up to 5 decimal points and always show decimal points
    cout << "time (s):" << setw(30) << time << endl;
    cout << "Surrounding temp (K):" << setw(20) << currentTemp << endl;
    cout << "Initial temperature (K):" << setw(16) << initTemp << endl;
    cout << "Cooling constant (1/s):" << setw(16) << coolingConstant << endl;
    cout << "Temp at a certain time:" << setw(16) << tempAtDesiredTime << endl;

    // Displaying the user outputs as well as the result calculated temp

    return 0;
}


