#pragma once
#include <iostream>
#include "lancha.h"

using namespace std;

class game {
	public:
		void printPlayersInfo(lancha p1, lancha p2);
		void selectWinner(lancha p1, lancha p2);
		void playerTurn(lancha &p, int& pDice, int pTurn);
};

