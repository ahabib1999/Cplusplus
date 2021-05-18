

#ifndef Date_H
#define Date_H
#include <string>

using namespace std;

class Date

// Class Definition
{
private:
    int month, day, year;
    char format;

// Private members

public:
    Date();
    Date(int month, int day, int year);
    void Input();
    void Show();
    bool Set(int m, int d, int y);
    bool SetFormat(char f);
    void Increment(int numDays = 1);
    int Compare(const Date& d);
    bool IsDateValid(int month, int day, int year);
    int GetValidDaysOfMonth(int month, int year);
    int CheckForLeapYear(int year);
    int GetMonth();
    int GetDay();
    int GetYear();
    void DisplayDefault();
    void DisplayTwoDigit();
    void DisplayLong();
    void DisplayJulian();

// Public members
};

#endif

