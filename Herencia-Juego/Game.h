#pragma once
#include <iostream>
#include <string>
#include "Personaje.h"
#include "Enemigo.h"
#include "EnemigoFinal.h"
#include <Windows.h>

using namespace std;


class Game {

public:
	//Game();
	void mostrarTablero(Personaje p1); //crea el tablero y posiciona el heroe
	void posicionarEnemigos(Enemigo e[], int num, Personaje p, EnemigoFinal ef);
	bool checkCasilla(Personaje p1, int num, Enemigo p2[], EnemigoFinal p3);

	void batalla(Personaje& p1, Personaje &p2);

};