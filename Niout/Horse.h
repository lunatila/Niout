#pragma once
#include <GL/glut.h>
#include "Circle.h"

struct Horse
{
	bool willMove = false;
	bool isOntheTable = false;

	Circle initialPosition, finalPosition;
	int atualSpot = 1, finalSpot;

	int Weight = 1;
	// Se o cavalo estiver na casa especial exterior esse valor é 2
};

