/* Name: Akbar Habib 
Date: 09/16/2020 
Section: 0010.fa20
Assignment: Assignment 4 
Due Date: 09/20/2020
About this project: Asks the user to enter 3 numbers and displays them in ascending order
Assumptions: user will always enter integers 
All work below was performed by Akbar Habib 
*/

#include <iostream> // required for inputting and outputting data

using namespace std; // namespace required for using cout

int main() // start of main function
{
    int num1; // variable for first number
    int num2; // variable for second number
    int num3; // variable for third number

    cout << "Welcome to the Ordered Numbers program" << endl; // Displays the welcome message to the user

    cout << "Please enter the first number "; // prompt for entering the first number
    cin >> num1; // saves the user input

    if (isalpha(num1)) {
        cout << "You have entered the wrong input" << endl;
        cout << "Please enter a number (Like 1 or 99) " << endl;
        cin >> num1;
    }
    // Validates the input, displays the error message and takes the input again

    cout << "Please enter the second number "; // prompt for entering the second number
    cin >> num2; // saves the user input

    if (isalpha(num2)) {
        cout << "You have entered the wrong input" << endl;
        cout << "Please enter a number (Like 1 or 99) " << endl;
        cin >> num2;
    }
    // Validates the input, displays the error message and takes the input again

    cout << "Please enter the third number "; // prompt for entering the third number
    cin >> num3; // saves the user input

    if (isalpha(num3)) {
        cout << "You have entered the wrong input" << endl;
        cout << "Please enter a number (Like 1 or 99) " << endl;
        cin >> num3;
    }
    // Validates the input, displays the error message and takes the input again

    if (num1 == num2 && num2 == num3) // if all three numbers are equal
    {
        cout << "All the numbers are equal" << endl; // Display the ending message and end the program
    }

    else if (num1 <= num2 && num1 <= num3) // if the first number is lesser than or equal to the other two numbers
    {
        cout << num1 << endl; // Display the first number

        if (num2 <= num3) // if the second number is equal to or less than the third number
        {
            cout << num2 << endl;
            cout << num3 << endl;
        }

        else 
        { // if the third number is less than the second number
            cout << num3 << endl;
            cout << num2 << endl;
        }
    }

    else if (num2 <= num1 && num2 <= num3) // if the second number is less than or equal to the other two numbers
    {
        cout << num2 << endl; // Display the second number

        if (num1 <= num3) // if the first number is equal to or less than the third number
        { 
            cout << num1 << endl;
            cout << num3 << endl;
        }

        else // if the thrid number is less than the first number
        {
            cout << num3 << endl;
            cout << num1 << endl;
        }
    }

    else if (num3 <= num2 && num3 <= num1) // if the third number is less than or equal to the other two numbers
    {
        cout << num3 << endl; // Display the third number

        if (num2 <= num1) // if the second number is equal to or less than the first number
        {
            cout << num2 << endl;
            cout << num1 << endl;
        }

        else // if the first number is less than the second number
        {
            cout << num1 << endl;
            cout << num2 << endl;
        }
    }
}


