#include <iostream>
#include "lancha.h"
#include "Game.h"

using namespace std;

int main() {
	srand(time(NULL));
	game g;

	lancha p1(0.0, 0.0, 1, "Player1");
	lancha p2(0.0, 0.0, 1, "Player2");

	int turn = 0;
	int dice = 0;
	//int option = 0;

	while (turn < 5) {
		g.playerTurn(p1, dice, turn);
		g.playerTurn(p2, dice, turn);
		turn++;
	}
	g.selectWinner(p1, p2);
}