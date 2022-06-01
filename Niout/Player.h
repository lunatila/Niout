#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Horse.h"
using namespace std;

struct Player
{
	bool playAgain = true;
	int coinResult;
	Horse horse;
	int movement = 0;
	int playerColor;

	void tossCoins();

	void MO(); //int numberOfHorses?
	void NIOUT();
	void KUL();
	void KAI();
	void TO();
};

