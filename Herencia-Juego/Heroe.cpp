#include "Heroe.h"

Heroe::Heroe(int pHP, int pAttack, string pName, int pPosX, int pPosY, int pLevel) : Personaje(pHP, pAttack, pName, pPosX, pPosY) {
	level = pLevel;
}

void Heroe::setLevel(int pLevel) {
	level = pLevel;
}

void Heroe::movimiento(char direccion) {
	int newPos;
	//direccion = _getch();
	
	switch (direccion) {
	case 'w':
		if (getPosY() == 0) {
			cout << "Direccion invalida: final del tablero." << endl;
		}
		else {
			newPos = getPosY();
			newPos = newPos--;
			setPosY(newPos);
		}
		break;
	case 'a':
		if (getPosX() == 0) {
			cout << "Direccion invalida: final del tablero." << endl;
		}
		else {
			newPos = getPosX();
			newPos = newPos--;
			setPosX(newPos);
		}
		break;
	case 's':
		if (getPosY() == 9) {
			cout << "Direccion invalida: final del tablero." << endl;
		}
		else {
			newPos = getPosY();
			newPos = newPos++;
			setPosY(newPos);
		}
		break;
	case 'd':
		if (getPosX() == 4) {
			cout << "Direccion invalida: final del tablero." << endl;
		}
		else {
			newPos = getPosX();
			newPos = newPos++;
			setPosX(newPos);
		}
		break;
	default:
		cout << "Movimiento invalido.";
		break;
	}
}
