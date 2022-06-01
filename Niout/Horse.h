#pragma once
#include <GL/glut.h>
#include "Circle.h"
#include "GrafoTeste.h"

struct Horse
{
	bool willMove = false;
	bool isOntheTable = false;
	int color = 0;

	Circle initialPosition, finalPosition;
	int atualSpot = 1, finalSpot;

	int Weight = 1;
	// Se o cavalo estiver na casa especial exterior esse valor é 2

	void setColor(int i) {
		color = i;
	}
};

