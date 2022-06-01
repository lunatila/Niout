#pragma once
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

class Circle
{
public:
	float xCenter, yCenter;
	float radius;
	float pi = 3.1415;
	int index = 1;

	Circle() {
		float angle = 2 * pi * 6 / 20; // circulo inicial da corrida
		index = 1;
		radius = 0.05;
		xCenter = 0.8 * cos(angle);
		yCenter = 0.8 * sin(angle);
		
	}
	Circle(float x, float y, float r) {
		xCenter = x;
		yCenter = y;
		radius = r;
	}
	Circle(Circle &circle) {
		index = circle.index;
		xCenter = circle.xCenter;
		yCenter = circle.yCenter;
		radius = circle.radius;
	}
	void drawCircle();
	void showCircle();

	friend bool operator== (const Circle& lhs, const Circle& rhs)
	{
		return (lhs.xCenter == rhs.xCenter) &&
			   (lhs.yCenter == rhs.yCenter) &&
			   (lhs.radius == rhs.radius) &&
			   (lhs.index == rhs.index);
	}
};

