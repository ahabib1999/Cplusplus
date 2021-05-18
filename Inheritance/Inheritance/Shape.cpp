#include "Shape.h"
#include <iostream>

using namespace std;

// *****************************************************************
// * Function Name: Shape() *
// * Description: Default constructor for the class *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Shape::Shape()
{
	area = 1.00;
	perimeter = 1.00;
}

// *****************************************************************
// * Function Name: Shape(double a, double p) *
// * Description: Constructor with two params *
// * Parameter Description: double a : The area property of the shape *
// * double p : The perimeter property of the shape *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Shape::Shape(double a, double p)
{
	if (a < 1.00 && p < 1.00)
	{
		area = 1.00;
		perimeter = 1.00;
	}

	else if (a < 1.00)
	{
		area = 1.00;
		perimeter = p;
	}

	else if (p < 1.00)
	{
		area = a;
		perimeter = 1.00;
	}

	else
	{
		area = a;
		perimeter = p;
	}
}

// *****************************************************************
// * Function Name: GetArea() *
// * Description: Returns the area of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

double Shape::GetArea()
{
	return area;
}

// *****************************************************************
// * Function Name: SetArea(double Area) *
// * Description: Sets the area of the shape *
// * Parameter Description: double Area : The new area value *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Shape::SetArea(double Area)
{
	if (Area >= 1.00)
	{
		area = Area;
	}
	else
	{
		area = 1.00;
	}
}

// *****************************************************************
// * Function Name: GetPerimeter() *
// * Description: Returns the perimeter of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

double Shape::GetPerimeter()
{
	return perimeter;
}

// *****************************************************************
// * Function Name: SetPerimeter(double Perimeter) *
// * Description: Sets the area of the shape *
// * Parameter Description: double Perimeter : The new perimeter value *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Shape::SetPerimeter(double Perimeter)
{
	if (Perimeter >= 1.00)
	{
		perimeter = Perimeter;
	}
	else
	{
		perimeter = 1.00;
	}
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

void Shape::PrintData()
{
	cout << "Area is " << area << endl;
	cout << "Perimeter is " << perimeter << endl;
}