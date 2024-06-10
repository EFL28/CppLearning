#pragma once
#include <iostream>
#include "Personaje.h"
class EnemigoFinal : public Personaje {

public:
	EnemigoFinal(int pHP, int pAttack, string pName, int pPosX, int pPosY, int pSuperAttack1, int pSuperAttack2);


	void setSuperAttack1(int pSuperAttack1);
	void setSuperAttack2(int pSupperAttack2);

	int getSuperAttack1();
	int getSuperAttack2();


private:
	int superAttack1;
	int superAttack2;

};
