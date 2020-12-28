#include <iostream>
using namespace std;

int main()
{
    int totalSum = 0;

    for (int i = 1; i < 201; i++) {

        if (i % 3 == 0) {
            totalSum += i;
        }
    }

    cout << "The sum is: " << totalSum << endl;
    return 0;
}
