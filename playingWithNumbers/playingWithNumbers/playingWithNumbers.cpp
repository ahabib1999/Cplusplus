#include <iostream> // library required for inputing and outputing data
using namespace std; // namespace used for the cout object

void getValidUserInputPosNumGT0(int& num);
long double factorial(int num);
long double alternatingFactorial(int num);
int getValidOptionInput(int userInput);
void displayMenu();
// Function prototypes

int main()
{
    int num;
    long double numFactorial;
    int userInput;
    long double altFactorial;
    // Declaration of local variables 

    cout << "Welcome to the playing with numbers program !" << endl; // Displaying welcome message to the user

    displayMenu();
    cout << "Select an option (1, 2, 3): "; // Prompt asking the user to select menu option
    cin >> userInput; // user input saved into userInput

    userInput = getValidOptionInput(userInput); // Function call and saving the return value

    while (userInput != 3) // runs while user does not enter 3 
    {
        getValidUserInputPosNumGT0(num); // Function call

        if (userInput == 1) // if user chooses option 1
        {
            numFactorial = factorial(num); // Factorial function call and saving the return value
            cout << "Factorial (" << num << "): " << numFactorial << endl; // Displaying the factorial value to the user
        }

        else if (userInput == 2) // if user chooses option 2 
        {
            altFactorial = alternatingFactorial(num); // Alternating Factorial function call and saving the return value
            cout << "AlternatingFactorial(" << num << "): " << altFactorial << endl; // Displaying the alternating factorial value to the user
        }

        displayMenu();
        cout << "Select an option (1, 2, 3): "; // Asking the prompt to select a menu option again
        cin >> userInput; // input gets saved
        userInput = getValidOptionInput(userInput); // Function call and saving the return value
    }
    cout << "Thank you for using the program" << endl; // once user chooses option 3, thank you message displayed to the user and program ends
}

void displayMenu() // Function for displaying menu options 
{
    cout << "1) Compute the factorial of a number" << endl;
    cout << "2) Compute the alternating factorial of a number" << endl;
    cout << "3) Quit" << endl;
}

int getValidOptionInput(int userInput) { // Function definition
    while (userInput < 1 || userInput > 3) // Validating the input to check if it is within the valid range 
    {
        cout << "Please enter a valid option (1, 2, 3): "; // if not, prompting user to enter a valid input
        cin >> userInput;
    }
    return userInput; // returning the validated user input back
}

void getValidUserInputPosNumGT0(int& num) { // Function definition

    cout << "Enter a number greater than 0: "; // Prompt to enter number greater than 0
    cin >> num; // input gets saved

    while (num <= 0) // Validating the input 
    {
        cout << "You have entered a number less than or equal to 0" << endl; // Error message displayed for invalid input
        cout << "Enter a number greater than 0: "; // Asking for valid input
        cin >> num;
    }
}

long double factorial(int num) { // Function definition

    long double factorial = num; // variable declared and initialized

    while (num - 1 > 0) // run while num - 1 is greater than 0 
    {
        num = num - 1; // the value of num gets updated
        factorial *= num; // the updated num value is multiplied into the current factorial value
    }
    return factorial; // the final factorial value is returned
}

long double alternatingFactorial(int num) { // Function definition
    long double currentNumFactorial;
    long double alternatingFactorial = 0;
    // Variables declared and/or initialized

    for (int i = 1; i <= num; i++) { // loops from 1 to the num variable value
        currentNumFactorial = factorial(i); // Function call to the factorial method with the current i value as parameter

        if (num % 2 != 0) { // if num is odd
            
            if (i % 2 == 0) { // if current i value is even
                currentNumFactorial *= -1; // alternate the sign of the currentNumFactorial
            }
        }

        else { // if num is even

            if (i % 2 != 0) { // if current i is odd
                currentNumFactorial *= -1; // change the sign of the currentNumFactorial
            }
        }

        alternatingFactorial += currentNumFactorial; // increment the alternatingFactorial with the value of the currentNumFactorial
    }
    return alternatingFactorial; // return the alternatingFactorial
}
