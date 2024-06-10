#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


class Personaje {

public:
	//constructor
	Personaje(int pHP, int pAttack, string pName, int pPosY, int pPosX);
	Personaje();

	//setters
	void setHP(int pHP);
	void setAttack(int pAttack);
	void setName(string pName);
	void setPosX(int pPosX);
	void setPosY(int pPosY);

	//getters
	int getHP();
	int getAttack();
	string getName();
	int getPosX();
	int getPosY();

	//metodos



private:
	int vida;
	int ataque;
	string nombre;
	int posX;
	int posY;

};