#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include "Shape.h"

using namespace std;

class Triangle : public Shape
{
private:
	double side1;
	double side2;
	double side3;

public:
	Triangle();
	Triangle(double l, double w, double h);
	double GetLength();
	void SetLength(double l);
	double GetWidth();
	void SetWidth(double w);
	double GetHeight();
	void SetHeight(double h);
	void CalculateArea();
	void CalculatePerimeter();
	void PrintData();
};

#endif