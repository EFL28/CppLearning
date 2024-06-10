#pragma once
#include <iostream>
#include "Personaje.h"
#include <conio.h>

class Heroe : public Personaje {

public:
	Heroe(int pHP, int pAttack, string pName, int pPosX, int pPosY, int pLevel);

	void setLevel(int pLevel);

	int getLevel();

	void movimiento(char direccion);



private:
	int level;

};