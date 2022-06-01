#include "Player.h"

void Player::tossCoins()
{
	int coin1, coin2, coin3, coin4;

	string play[] = { "TO", "KAI", "KAI", "KUL", "KAI", "KUL", "KUL", "NIOUT", "KAI",
	"KUL", "KUL", "NIOUT", "KUL", "NIOUT", "NIOUT", "MO" };

	coin1 = rand() % 2; // 0 ou 1 (faces da moeda)
	coin2 = rand() % 2;
	coin3 = rand() % 2;
	coin4 = rand() % 2;

	coinResult = 1 * coin1 + 2 * coin2 + 4 * coin3 + 8 * coin4;
	// valor de 0 a 15, com uma lógica igual aos vértices dos Marching Squares
	// MO: 15
	// NIOUT: 14, 13, 11, 7
	// KUL: 12, 10, 9, 6, 5, 3
	// KAI: 8, 4, 2, 1
	// TO: 0
	switch (coinResult) {
	case 0:
		movement = 1;
		break;
	case 1: case 2: case 4: case 8:
		movement = 2;
		break;
	case 12: case 10: case 9: case 6: case 5: case 3:
		movement = 3;
		break;
	case 14: case 13: case 11: case 7:
		movement = 4;
		playAgain = true;
		break;
	case 15:
		movement = 5;
		playAgain = true;
		break;
	}

	cout << "Jogada: " << coin1 << ", " << coin2 << ", " << coin3 << ", " << coin4 << " -> ";
	cout << play[coinResult] << "!" << endl;

}

void Player::MO()
{
	int movement = 5;

	for (int i = 0; i < 4; i++) {
		//for (int i = 0; i <= movement; i++)
		if (horse.willMove == true) {
			horse.initialPosition.index += movement;
			if (horse.initialPosition.index % 5 == 0)
				horse.Weight = 2;
			else
				horse.Weight = 1;
		}
	}

	playAgain = true;
}
void Player::NIOUT()
{
	int movement = 4;

	for (int i = 0; i < 4; i++) {
		//for (int i = 0; i <= movement; i++)
		if (horse.willMove == true) {
			horse.initialPosition.index += movement;
			if (horse.initialPosition.index % 5 == 0)
				horse.Weight = 2;
			else
				horse.Weight = 1;
		}
	}

	playAgain = true;
}
void Player::KUL()
{
	int movement = 3;

	for (int i = 0; i < 4; i++) {
		//for (int i = 0; i <= movement; i++)
		if (horse.willMove == true) {
			horse.initialPosition.index += movement;
			if (horse.initialPosition.index % 5 == 0)
				horse.Weight = 2;
			else
				horse.Weight = 1;
		}
	}
}
void Player::KAI()
{
	int movement = 2;

	for (int i = 0; i < 4; i++) {
		//for (int i = 0; i <= movement; i++)
		if (horse.willMove == true) {
			horse.initialPosition.index += movement;
			if (horse.initialPosition.index % 5 == 0)
				horse.Weight = 2;
			else
				horse.Weight = 1;
		}
	}
}
void Player::TO()
{
	int movement = 1;

	for (int i = 0; i < 4; i++) {
		//for (int i = 0; i <= movement; i++)
		if (horse.willMove == true) {
			horse.initialPosition.index += movement;
			if (horse.initialPosition.index % 5 == 0)
				horse.Weight = 2;
			else
				horse.Weight = 1;
		}
	}
}