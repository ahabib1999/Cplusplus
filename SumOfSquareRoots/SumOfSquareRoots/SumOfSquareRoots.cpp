#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int userInput;
    double sumSqrRoot = 0;

    cout << "Enter the numbers:" << endl;
    cin >> userInput;

    while (userInput != 0) {

        int newNum = abs(userInput);
        double numSqrRoot = sqrt(newNum);

        sumSqrRoot += numSqrRoot;

        cin >> userInput;
    }

    cout << "The sum is " << sumSqrRoot;
}
