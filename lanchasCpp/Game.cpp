#include "game.h"

void game::printPlayersInfo(lancha p1, lancha p2) {
	p1.printStats();
	p2.printStats();
}

void game::selectWinner(lancha p1, lancha p2) {
	cout << "----FINAL----" << endl;

	if (p1.getDistance() > p2.getDistance()) {
		cout << "The player " << p1.getName() << " has driven " << p1.getDistance() << endl;
		cout << "The player " << p2.getName() << " has driven " << p2.getDistance() << endl;
		cout << "The race winner is: " << p1.getName() << endl;
	}
	else if (p1.getDistance() < p2.getDistance()) {
		cout << "The player " << p1.getName() << " has driven " << p1.getDistance() << endl;
		cout << "The player " << p2.getName() << " has driven " << p2.getDistance() << endl;
		cout << "The race winner is: " << p2.getName() << endl;
	}
	else {
		cout << "Both players have ridden " << p1.getDistance() << endl;
		cout << "The race ends in a draw." << endl;
	}
}

void game::playerTurn(lancha &p, int &pDice, int pTurn) {
	cout << "-------TURNO " << p.getName() << "-------" << endl;
	//inicio turno P1
	pDice = rand() % 6 + 1;
	cout << "Speed obtained: " << pDice << endl;

	if (pTurn == 0) {
		p.setSpeed(pDice); //primer turno setea velocidad inicial
	}
	else {
		p.updateSpeed(pDice); // 2o,3o,4o,5o turno se actualiza la inicial con la suma
	}

	int option = 0;

	if (p.getNitro() == 1) {
		while (option != 1 && option != 2) { //esto se puede reutilizar
			cout << "Do you want to use the nitro?" << endl;
			cout << "1.- Yes" << endl;
			cout << "2.- No" << endl;

			cin >> option;

			if (option != 1 && option != 2) { //opcion incorrecta
				cout << "Incorrect option, try again." << endl;
			}
		}
	}

	if (option == 1) {
		p.useNitro();
		float dist = p.calcDistance();
		p.setDistance(dist);
	}
	else {
		float dist = p.calcDistance();
		p.setDistance(dist);
	}
	p.printStats();
}
