#include <iostream>
#include <iomanip>
using namespace std;

struct StockData
{
    string StockName{}; // name of Stock
    double price[4]{}; //price
    float highestPrice{}; //highest price
};

//structure for Stock data

void getHighestPrice(StockData &stock );
void displayStockData(StockData &stock );
void displayMenu();
char getValidUserInput();

// Function Prototypes

int main()
{

    StockData stocks[3];
    StockData stockA, stockB, stockC;
    char userInput;

    // Declaring and / or initializing local variables

    stocks[0].StockName = "GE";
    stocks[0].price[0] = 47.88;
    stocks[0].price[1] = 56.99;
    stocks[0].price[2] = 98.66;
    stocks[0].price[3] = 45.77;

    // Attributes for the first instance of the structure

    stocks[1].StockName = "ATT";
    stocks[1].price[0] = 66.99;
    stocks[1].price[1] = 45.33;
    stocks[1].price[2] = 32.99;
    stocks[1].price[3] = 34.99;

    // Attributes for the second instance of the structure

    stocks[2].StockName = "MPS";
    stocks[2].price[0] = 88.99;
    stocks[2].price[1] = 99.78;
    stocks[2].price[2] = 76.99;
    stocks[2].price[3] = 66.99;

    // Attributes for the third instance of the structure

    cout << "Welcome to the Stocks Data program" << endl; // Display welcome message
    displayMenu(); // Function call to display menu
    userInput = getValidUserInput(); // Function call to get valid user input

    while (userInput != 'C') // Runs while user enters option C
    {
        if (userInput == 'A')
        {
            for (int i = 0; i < 3; i++) {
                getHighestPrice(stocks[i]);
            }

            // Get highest price for each instance of the structure
        }

        else
        {
            for (int i = 0; i < 3; i++) {
                displayStockData(stocks[i]);
            }

            // Display the stock data for each instance of the structure
        }

        displayMenu();
        userInput = getValidUserInput();
    }

    cout << "Thanks for using the program" << endl; // Display thank you message to the user
}

void displayMenu() // Function definition for displaying menu options
{
    cout << "Menu Options:" << endl;
    cout << "A) Compute Highest Price" << endl;
    cout << "B) Display Stock Data" << endl;
    cout << "C) Quit" << endl;
    cout << endl;

    // Displaying menu options
}

char getValidUserInput() // Function definiton foe getting valid user input
{
    char userInput;

    cout << "Please select an option (A-C)... " << endl; // Prompt to enter option
    cin >> userInput; // Saving the input
    userInput = toupper(userInput); // Converting to uppercase
    
    while (userInput != 'A' && userInput != 'B' && userInput != 'C')
    {
        cout << "You have entered an invalid option" << endl;
        cout << "Please select 'A', 'B', or 'C': " << endl;
        cin >> userInput;
        userInput = toupper(userInput);
    }

    // Runs while invalid input is entered

    cout << endl;
    return userInput; // Returns the user input
}

void getHighestPrice(StockData &stock ) // Function definiton for getting highest price
{
    double highestPrice = 0;

    for (int i = 0; i < 4; i++)
    {
        if (stock.price[i] > highestPrice)
        {
            highestPrice = stock.price[i];
        }
    }

    // Loops through the price array to get the highest price

    stock.highestPrice = highestPrice; // Updating the highest price attribute of the stock
}

void displayStockData(StockData &stock ) // Fuction definiton for displaying stock data
{
    cout << "Stock Name: " << stock.StockName << endl; // Displaying the name of the stock
    
    for (int i = 0; i < 4; i++)
    {
        cout << "Price: " << setw(30) << stock.price[i] << endl;
    }

    // Displaying all the prices of the stock

    getHighestPrice(stock); // Updating the highest price of the stock

    cout << "Highest price: " << setw(22) << stock.highestPrice << endl; // Displaying the highest price of the stock
}
