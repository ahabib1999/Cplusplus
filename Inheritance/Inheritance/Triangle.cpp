#include "Triangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// *****************************************************************
// * Function Name: Triangle() *
// * Description: Default constructor for the class *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Triangle::Triangle()
{
	side1 = 1.00;
	side2 = 1.00;
	side3 = 1.00;
}

// *****************************************************************
// * Function Name: Triangle(double l, double w, double h) *
// * Description: Constructor with three params *
// * Parameter Description: double l : The length property of the shape *
// * double w : The width property of the shape *
// * double h : The height property of the shape *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Triangle::Triangle(double l, double w, double h)
{
	if (l < 1.00 && w < 1.00 && h < 1.00)
	{
		side1 = 1.00;
		side2 = 1.00;
		side3 = 1.00;
	}
	else if (l < 1.00)
	{
		side1 = 1.00;
		side2 = w;
		side3 = h;
	}
	else if (w < 1.00)
	{
		side1 = l;
		side2 = 1.00;
		side3 = h;
	}
	else if (h < 1.00)
	{
		side1 = l;
		side2 = w;
		side3 = 1.00;
	}
	else
	{
		side1 = l;
		side2 = w;
		side3 = h;
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

double Triangle::GetLength()
{
	return side1;
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

void Triangle::SetLength(double l)
{
	if (l < 1.00)
	{
		side1 = 1.00;
	}
	else
	{
		side1 = l;
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

double Triangle::GetWidth()
{
	return side2;
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

void Triangle::SetWidth(double w)
{
	if (w < 1.00)
	{
		side2 = 1.00;
	}
	else
	{
		side2 = w;
	}
}

// *****************************************************************
// * Function Name: GetHeight() *
// * Description: Returns the third side of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

double Triangle::GetHeight()
{
	return side3;
}

// *****************************************************************
// * Function Name: SetHeight(double h) *
// * Description: Sets the third side of the shape to a new value *
// * Parameter Description: h : The new width value *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Triangle::SetHeight(double h)
{
	side3 = h;
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

void Triangle::CalculateArea()
{
	double area;
	double s = (side1 + side2 + side3) / 2;
	double square = s * (s - side1) * (s - side2) * (s - side3);
	area = sqrt(abs(square));
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

void Triangle::CalculatePerimeter()
{
	double perimeter;
	perimeter = side1 + side2 + side3;
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

void Triangle::PrintData()
{
	cout << "One side of this triangle is " << fixed << setprecision(2) << side1 << endl;
	cout << "One side of this triangle is " << fixed << setprecision(2) << side2 << endl;
	cout << "One of this triangle is " << fixed << setprecision(2) << side3 << endl;
	CalculateArea();
	cout << "The area of this triangle is " << fixed << setprecision(2) << GetArea() << endl;
	CalculatePerimeter();
	cout << "The perimeter of this triangle is " << fixed << setprecision(2) << GetPerimeter() << endl;
}