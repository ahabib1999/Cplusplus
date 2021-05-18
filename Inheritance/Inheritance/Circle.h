#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
using namespace std;
#include "Shape.h"
class Circle : public Shape
{
private:
	double radius;

public:
	Circle();
	Circle(double r);
	double GetRadius();
	void SetRadius(double Radius);
	void PrintData();
	void CalculateArea();
	void CalculatePerimeter();
};

#endif