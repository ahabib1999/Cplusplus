#include "date.h"
#include <iostream>
#include <string>
#include<sstream>

using namespace std;

// *****************************************************************
// * Function Name: Date *
// * Description: Constructor for the Date class with no params *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Date::Date()
{
	month = 1;
	day = 1;
	year = 2000;
	format = 'D';
}

// *****************************************************************
// * Function Name: Date *
// * Description: Constructor for the Date class with multiple params *
// * Parameter Description: *
// * m (int): the month field value for new Date object *
// * d (int): the day field value for new Date object *
// * y (int): the year field value for new Date object *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Date::Date(int m, int d, int y)
{
	bool isdatevalid = IsDateValid(m, d, y);

	if (isdatevalid == false)
	{
		month = 1;
		day = 1;
		year = 2000;
	}

	else
	{
		month = m;
		day = d;
		year = y;
	}

	format = 'D';
}

// *****************************************************************
// * Function Name: IsDateValid *
// * Description: Function validating whether a date is valid *
// * Parameter Description: *
// * month (int): the month value to be validated *
// * day (int): the day value to be validated *
// * year (int): the year value to be validated *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

bool Date::IsDateValid(int month, int day, int year)
{
	int numdays = GetValidDaysOfMonth(month, year);

	if (month < 1 || month > 12 || year < 1582 || day < 1 || day > numdays)
	{
		return false;
	}

	else if (year == 1582 && month < 10)
	{
		return false;
	}

	else
	{
		return true;
	}
}

// *****************************************************************
// * Function Name: GetValidDaysOfMonth *
// * Description: Function getting the number of days for each month *
// * Parameter Description: *
// * month (int): Referencing the passed in month *
// * year (int): Referencing the passed in year *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Date::GetValidDaysOfMonth(int month, int year)
{
	int numdays = 0;

	switch (month)
	{
	case 1:
		numdays = 31;
		break;

	case 2:
		numdays = CheckForLeapYear(year);
		break;

	case 3:
		numdays = 31;
		break;

	case 4:
		numdays = 30;
		break;

	case 5:
		numdays = 31;
		break;

	case 6:
		numdays = 30;
		break;

	case 7:
		numdays = 31;
		break;

	case 8:
		numdays = 31;
		break;

	case 9:
		numdays = 30;
		break;

	case 10:
		numdays = 31;
		break;

	case 11:
		numdays = 30;
		break;

	case 12:
		numdays = 31;
		break;
	}

	return numdays;
}

// *****************************************************************
// * Function Name: CheckForLeapYear *
// * Description: Function checking whether the passed in year is a leap year *
// * Parameter Description: *
// * year (int): Referencing the passed in year *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Date::CheckForLeapYear(int year)
{
	int numdays = 0;
	if (year % 100 == 0 && year % 400 == 0)
	{
		numdays = 29;
	}

	else if (year % 100 != 0 && year % 4 == 0)
	{
		numdays = 29;
	}

	else
	{
		numdays = 28;
	}

	return numdays;
}

// *****************************************************************
// * Function Name: GetMonth *
// * Description: Accessor method for the month member of Date class *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Date::GetMonth()
{
	return month;
}

// *****************************************************************
// * Function Name: GetDay *
// * Description: Accessor method for the day member of Date class *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Date::GetDay()
{
	return day;
}

// *****************************************************************
// * Function Name: GetYear *
// * Description: Accessor method for the year member of Date class *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Date::GetYear()
{
	return year;
}

// *****************************************************************
// * Function Name: Input *
// * Description: Function allowing user to enter in a valid date for a Date object *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Date::Input()
{
	int newmonth, newday, newyear;
	bool isdatevalid;

	char divider = '/';

	cout << "Please enter in a date in the format of mm/dd/yyyy" << endl;
	cin >> newmonth >> divider >> newday >> divider >> newyear;

	isdatevalid = IsDateValid(newmonth, newday, newyear);

	while (isdatevalid == false)
	{
		cout << "Invalid date, please try again" << endl;
		cout << "Please enter in a date in the format of mm/dd/yyyy" << endl;
		cin >> newmonth >> divider >> newday >> divider >> newyear;

		isdatevalid = IsDateValid(newmonth, newday, newyear);
	}

	month = newmonth;
	day = newday;
	year = newyear;
}

// *****************************************************************
// * Function Name: Set *
// * Description: Function setting new values for the month, day, and year fields of a Date object *
// * Parameter Description: *
// * m (int): the new month value for the Date object *
// * d (int): the new day value for the Date object *
// * y (int): the new year value for the Date object *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

bool Date::Set(int m, int d, int y)
{
	bool isdatevalid = IsDateValid(m, d, y);

	if (isdatevalid == false)
	{
		return false;
	}

	else
	{
		month = m;
		day = d;
		year = y;
		return true;
	}
}

// *****************************************************************
// * Function Name: Increment *
// * Description: Function incrementing a date by the number of days passed in *
// * Parameter Description: *
// * numdays (int): Referencing the passed in number of days *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Date::Increment(int numdays)
{
	day += numdays;

	int maxnumdays = GetValidDaysOfMonth(month, year);

	if (day > maxnumdays)
	{
		if (month == 12)
		{
			year++;
			month = 1;
			day -= maxnumdays;
		}

		else
		{
			month++;
			day -= maxnumdays;
		}
	}
}

// *****************************************************************
// * Function Name: Compare *
// * Description: Function comapring two Date objects *
// * Parameter Description: *
// * d (Date&): Referencing the passed in Date object *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int Date::Compare(const Date& d)
{
	int compare;

	if (year <= d.year)
	{
		if (year < d.year)
		{
			return -1;
		}

		else
		{
			if (month <= d.month)
			{
				if (month < d.month)
				{
					return -1;
				}

				else
				{
					if (day <= d.day)
					{
						if (day < d.day)
						{
							return -1;
						}

						else
						{
							return 0;
						}
					}

					else
					{
						return 1;
					}
				}
			}

			else
			{
				return 1;
			}
		}
	}

	else
	{
		return 1;
	}
}

// *****************************************************************
// * Function Name: SetFormat *
// * Description: Function setting the default format for Date objects *
// * Parameter Description: *
// * year (int): Referencing the passed in format identifier *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************


bool Date::SetFormat(char f)
{
	if (f == 'D' || f == 'T' || f == 'L' || f == 'J')
	{
		format = f;
		return true;
	}

	return false;
}

// *****************************************************************
// * Function Name: Show *
// * Description: Function displaying the date to the user in the specified format *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Date::Show()
{
	switch (format)
	{
	case 'D':
		DisplayDefault();
		break;

	case 'T':
		DisplayTwoDigit();
		break;

	case 'L':
		DisplayLong();
		break;

	case 'J':
		DisplayJulian();
		break;
	}
}

// *****************************************************************
// * Function Name: DisplayDefault *
// * Description: Function displaying the date to the user in the default format *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Date::DisplayDefault()
{
	cout << month << "/" << day << "/" << year << endl;
}

// *****************************************************************
// * Function Name: DisplayTwoDigit *
// * Description: Function displaying the date to the user in the two digit format *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Date::DisplayTwoDigit()
{
	stringstream stream;
	stream << year;
	string stryear = stream.str();
	string twodigityear = stryear.substr(2, 4);

	if (month < 10 || month >= 10)
	{

		if (month < 10)
		{
			cout << "0" << month;
		}
		
		else
		{
			cout << month;
		}
		cout << "/";

		if (day < 10)
		{
			cout << "0" << day;
		}

		else
		{
			cout << day;
		}
		cout << "/";
	}
	cout << twodigityear << endl;
}

// *****************************************************************
// * Function Name: DisplayLong *
// * Description: Function displaying the date to the user in the long format *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Date::DisplayLong()
{
	string abbreviatedmonth;

	switch (month)
	{
	case 1:
		abbreviatedmonth = "Jan";

	case 2:
		abbreviatedmonth = "Feb";

	case 3:
		abbreviatedmonth = "Mar";

	case 4:
		abbreviatedmonth = "Apr";

	case 5:
		abbreviatedmonth = "May";

	case 6:
		abbreviatedmonth = "June";

	case 7:
		abbreviatedmonth = "July";

	case 8:
		abbreviatedmonth = "Aug";

	case 9:
		abbreviatedmonth = "Sept";

	case 10:
		abbreviatedmonth = "Oct";

	case 11:
		abbreviatedmonth = "Nov";

	case 12:
		abbreviatedmonth = "Dec";
	}

	cout << abbreviatedmonth << " " << day << ", " << year << endl;
}

// *****************************************************************
// * Function Name: Show *
// * Description: Function displaying the date to the user in the julian format *
// * Parameter Description: N/A *
// * Date: 01/29/2021 *
// * Author: Akbar Habib *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Date::DisplayJulian()
{
	int monthdifference = month - 1;
	int julianday = 0;
	
	for (int i = 0; i < monthdifference; i++)
	{
		int maxmonthdays = GetValidDaysOfMonth(month - 1, year);

		julianday += maxmonthdays;
	}

	julianday += day;

	cout << julianday << ", " << year << endl;
}