#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	Square square1; // Test the default constructor
	Square square2(5.00); // Test the constructor with one param

	square1.PrintData();
	square2.PrintData();

	// Display the shape data for both objects

	square1.SetLength(6.00); // Test the Setter function 
	cout << "The new length of the square is " << square1.GetLength() << endl; // Test the getter function

	cout << endl;

	Circle circle1;
	Circle circle2(10.00);

	circle1.PrintData();
	circle2.PrintData();

	circle1.SetRadius(5.00);
	cout << "The new radius of the circle is " << circle1.GetRadius() << endl;

	cout << endl;

	Rectangle rect1;
	Rectangle rect2(4.00, 6.00); // Test the constructor with two params

	rect1.PrintData();
	rect2.PrintData();

	rect1.SetLength(5.00); // Test the Setter function for the length property
	rect2.SetWidth(3.00); // Test the Setter function for the width property

	cout << "The new length of the rectangle is " << rect1.GetLength() << endl; // Test the getter function for the length property
	cout << "The new width of the square is " << rect2.GetWidth() << endl; // Test the getter function for the width property

	cout << endl;

	Triangle tri1;
	Triangle tri2(8.00, 5.00, 5.00); // Test the constructor with 3 params

	tri1.PrintData();
	tri2.PrintData();

	tri1.SetLength(20.00);
	tri2.SetWidth(30.00);
	tri1.SetHeight(45.00); // Test the setter function for the height property

	cout << "The new length of the triangle is " << tri1.GetLength() << endl;
	cout << "The new width of the triangle is " << tri2.GetWidth() << endl;
	cout << "The new height of the triangle is " << tri1.GetHeight() << endl; // Test the getter function for the height property

	cout << endl;

	square1.SetArea(50.00);  // Test the setter function for area
	tri2.SetPerimeter(100.00); // Test the setter function for perimeter

	cout << "The new area of the square is " << square1.GetArea() << endl; // Test the getter function for area
	cout << "The new perimeter of the triangle is " << tri2.GetPerimeter() << endl; // Test the getter function for perimeter
}