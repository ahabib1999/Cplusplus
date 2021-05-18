#include "Rectangle.h"
#include <iostream>
#include <iomanip>

using namespace std;

// *****************************************************************
// * Function Name: Rectangle() *
// * Description: Default constructor for the class *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Rectangle::Rectangle()
{
	length = 1.00;
	width = 1.00;
}

// *****************************************************************
// * Function Name: Rectangle(double l, double w) *
// * Description: Constructor with two params *
// * Parameter Description: double l : The length property of the shape *
// * double w : The width property of the shape *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Rectangle::Rectangle(double l, double w)
{
	if (l < 1.00 && w < 1.00)
	{
		length = 1.00;
		width = 1.00;
	}
	else if (l < 1.00)
	{
		length = 1.00;
		width = w;
	}
	else if (w < 1.00)
	{
		length = l;
		width = 1.00;
	}
	else
	{
		length = l;
		width = w;
	}
}

// *****************************************************************
// * Function Name: GetLength() *
// * Description: Returns the first side of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

double Rectangle::GetLength()
{
	return length;
}

// *****************************************************************
// * Function Name: SetLength(double l) *
// * Description: Sets the first side of the shape to a new value *
// * Parameter Description: double l : The new length value *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Rectangle::SetLength(double l)
{
	if (l < 1.00)
	{
		length = 1.00;
	}
	else
	{
		length = l;
	}
}

// *****************************************************************
// * Function Name: GetWidth() *
// * Description: Returns the second side of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

double Rectangle::GetWidth()
{
	return width;
}

// *****************************************************************
// * Function Name: SetWidth(double w) *
// * Description: Sets the second side of the shape to a new value *
// * Parameter Description: w : The new width value *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Rectangle::SetWidth(double w)
{
	if (w < 1.00)
	{
		width = 1.00;
	}
	else
	{
		width = w;
	}
}

// *****************************************************************
// * Function Name: CalculateArea() *
// * Description: Calculates the area of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Rectangle::CalculateArea()
{
	double area;
	area = length * width;
	SetArea(area);
}

// *****************************************************************
// * Function Name: CalculatePerimeter() *
// * Description: Calculates the perimeter of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Rectangle::CalculatePerimeter()
{
	double perimeter;
	perimeter = (2 * length) + (2 * width);
	SetPerimeter(perimeter);
}

// *****************************************************************
// * Function Name: PrintData() *
// * Description: Displays the details of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Rectangle::PrintData()
{
	cout << "The length of this rectangle is " << fixed << setprecision(2) << length << endl;
	cout << "The width of this rectangle is " << fixed << setprecision(2) << width << endl;
	CalculateArea();
	cout << "The area of this rectangle is " << fixed << setprecision(2) << GetArea() << endl;
	CalculatePerimeter();
	cout << "The perimeter of this rectangle is " << fixed << setprecision(2) << GetPerimeter() << endl;
}