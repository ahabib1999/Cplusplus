#include "Circle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// *****************************************************************
// * Function Name: Circle() *
// * Description: Default constructor for the class *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Circle::Circle()
{
	radius = 1.00;
}

// *****************************************************************
// * Function Name: Circle(double r) *
// * Description: Constructor with one param *
// * Parameter Description: double r : The radius property of the shape *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Circle::Circle(double r)
{
	if (r < 1.00)
	{
		radius = 1.00;
	}
	else
	{
		radius = r;
	}
}

// *****************************************************************
// * Function Name: GetRadius() *
// * Description: Returns the side of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

double Circle::GetRadius()
{
	return radius;
}

// *****************************************************************
// * Function Name: SetRadius(double radius) *
// * Description: Sets the side of the shape to a new value *
// * Parameter Description: double Radius: The new radius value *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Circle::SetRadius(double Radius)
{
	radius = Radius;
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

void Circle::CalculateArea()
{
	double pi = 2 * acos(0.0);
	double area;
	area = pi * radius * radius;
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

void Circle::CalculatePerimeter()
{
	double perimeter;
	double pi = 2 * acos(0.0);
	perimeter = pi * 2 * radius;
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

void Circle::PrintData()
{
	cout << "The radius of the Circle is " << fixed << setprecision(2) << radius << endl;
	CalculateArea();
	cout << "The area of the Circle is " << fixed << setprecision(2) << GetArea() << endl;
	CalculatePerimeter();
	cout << "The perimeter of the circle is " << fixed << setprecision(2) << GetPerimeter() << endl;
}