#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shape.h"

using namespace std;

class Rectangle : public Shape
{
private:
	double length;
	double width;

public:
	Rectangle(); // Default constructor for the class
	Rectangle(double l, double w); // Constructor with two params
	double GetLength();
	void SetLength(double l);

	// Getter and Setter functions for the first side

	double GetWidth();
	void SetWidth(double w);

	// Getter and Setter for the second side

	void PrintData(); // Function to print the details of the shape
	void CalculateArea(); // Function to calculate the area of the shape
	void CalculatePerimeter(); // Function to calculate the perimeter of the shape
};

#endif