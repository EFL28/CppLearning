#include "Personaje.h"

Personaje::Personaje(int pHP, int pAttack, string pName, int pPosY, int pPosX) {
	vida = pHP;
	ataque = pAttack;
	nombre = pName;
	posX = pPosX; 
	posY = pPosY;
}

Personaje::Personaje() {
}

void Personaje::setHP(int pHP) {
	vida = pHP;
}

void Personaje::setAttack(int pAttack) {
	ataque = pAttack;
}

void Personaje::setName(string pName) {
	nombre = pName;
}

void Personaje::setPosX(int pPosX) {
	posX = pPosX;
}

void Personaje::setPosY(int pPosY) {
	posY = pPosY;
}

int Personaje::getHP() {
	return vida;
}

int Personaje::getAttack() {
	return ataque;
}

string Personaje::getName() {
	return nombre;
}

int Personaje::getPosX() {
	return posX;
}

int Personaje::getPosY() {
	return posY;
}