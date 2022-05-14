#pragma once
#include <GL/glut.h>
#include "Circle.h"

class Horse
{

public:
	//Circle initialCircle;

	bool willMove = false;
	bool isOntheTable = false;

	Circle initialPosition;
	int atualSpot = 1, finalSpot;

	int Weight = 1;
	// Se o cavalo estiver na casa especial exterior esse valor é 2
};

