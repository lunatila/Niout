#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Horse.h"
using namespace std;

class Player
{
	Horse horses[4];
	bool playAgain = false;
	int coinResult;
public:
	int playerColor;

	void tossCoins();

	void MO(Horse horsesToMove[4]); //int numberOfHorses?
	void NIOUT(Horse horsesToMove[4]);
	void KUL(Horse horsesToMove[4]);
	void KAI(Horse horsesToMove[4]);
	void TO(Horse horsesToMove[4]);
};

