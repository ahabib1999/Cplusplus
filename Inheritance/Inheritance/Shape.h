#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Shape
{
private:
	double area;
	double perimeter;

public:

	Shape(); // Default constructor
	Shape(double a, double p); // Constructor with 2 params

	double GetArea();
	void SetArea(double Area);

	// Getter and setter for the area attribute

	double GetPerimeter();
	void SetPerimeter(double Perimeter);

	// Getter and setter for the perimeter attribute

	virtual void PrintData();

	// virtual print function defined for the base class
};

#endif