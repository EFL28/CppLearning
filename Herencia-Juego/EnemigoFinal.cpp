#include "EnemigoFinal.h"

EnemigoFinal::EnemigoFinal(int pHP, int pAttack, string pName, int pPosX, int pPosY, int pSuperAttack1, int pSuperAttack2) : Personaje(pHP, pAttack, pName, pPosX, pPosY) {
	superAttack1 = pSuperAttack1;
	superAttack2 = pSuperAttack2;
}

void EnemigoFinal::setSuperAttack1(int pSuperAttack1) {
	superAttack1 = pSuperAttack1;
}

void EnemigoFinal::setSuperAttack2(int pSuperAttack2) {
	superAttack2 = pSuperAttack2;
}

int EnemigoFinal::getSuperAttack1() {

	return superAttack1;
}

int EnemigoFinal::getSuperAttack2() {

	return superAttack2;
}