#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
using namespace std;
#include "Shape.h"

class Square : public Shape
{
private:
	double length;

public:
	Square(); // Default Constructor
	Square(double l); // Constructor with one param
	double GetLength();
	void SetLength(double Length);

	// Getter and Setter for the length property

	void PrintData(); // Overrides the virtual PrintData function
	void CalculateArea(); 
	void CalcuatePerimeter(); 

	// Functions for calculating the area and perimeter
};

#endif