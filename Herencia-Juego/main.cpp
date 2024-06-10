#include <iostream>
#include "Game.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "Heroe.h"
#include "EnemigoFinal.h"
#include <Windows.h>
#include <conio.h>


using namespace std;

const int ROWS = 10;
const int COLUMNS = 5;

int main() {
	srand(time(NULL));

	int exitX = rand() % 5;
	int heroX = rand() % 5;

	Game g;
	Heroe caballero(500, 100, "Knight", 0, heroX, 1);
	EnemigoFinal dragon(100, 100, "Dragon", 9, exitX, 30, 553);
	Enemigo hechiceros[3];

	g.posicionarEnemigos(hechiceros, 3, caballero, dragon); //posicionamos a los enemigos de manera aleatoria
	g.mostrarTablero(caballero); //tablero al inicio

	char move;
	bool pelea;
	
	while (caballero.getHP() > 0 && dragon.getHP() > 0) {
		move = _getch(); //char para mover al personaje
		caballero.movimiento(move); //movemos al heroe
		pelea = g.checkCasilla(caballero, 3, hechiceros, dragon); //comprobamos si encontramos un enemigo

		if (pelea) {
			if (caballero.getPosX() == dragon.getPosX() && caballero.getPosY() == dragon.getPosY()) {
				cout << "Has encontrado la salida pero hay un enemigo tapandote el paso." << endl;
				g.batalla(caballero, dragon);

			}

			for (int i = 0; i < 3; i++) {
				if (caballero.getPosX() == hechiceros[i].getPosX() && caballero.getPosY() == hechiceros[i].getPosY()) {
					cout << "Un enemigo te cierra el paso." << endl;
					g.batalla(caballero, hechiceros[i]);

				}
			}
		}
		//system("cls");
		
		g.mostrarTablero(caballero);
	}
	




}