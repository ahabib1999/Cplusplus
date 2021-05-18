#include "Square.h"
#include <iostream>
#include <iomanip>

using namespace std;

// *****************************************************************
// * Function Name: Square() *
// * Description: Default constructor for the class *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Square::Square()
{
	length = 1.00;
}

// *****************************************************************
// * Function Name: Square(double l) *
// * Description: Constructor with one param *
// * Parameter Description: double l : The length property of the shape *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

Square::Square(double l)
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
// * Function Name: GetLength() *
// * Description: Returns the side of the shape *
// * Parameter Description: N/A *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

double Square::GetLength()
{
	return length;
}

// *****************************************************************
// * Function Name: SetLength(double length) *
// * Description: Sets the first side of the shape to a new value *
// * Parameter Description: double length : The new length value *
// * Date: 03/05/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void Square::SetLength(double Length)
{
	length = Length;
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

void Square::CalculateArea()
{
	double area;
	area = length * length;
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

void Square::CalcuatePerimeter()
{
	double perimeter;
	perimeter = 4 * length;
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

void Square::PrintData()
{
	cout << "The length of the Square is " << fixed << setprecision(2) << length << endl;
	CalculateArea();
	cout << "The area of the Square is " << fixed << setprecision(2) << GetArea() << endl;
	CalcuatePerimeter();
	cout << "The perimeter of the Square is " << fixed << setprecision(2) << GetPerimeter() << endl;
}