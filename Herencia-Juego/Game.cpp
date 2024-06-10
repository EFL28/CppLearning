#include "Game.h"

void Game::mostrarTablero(Personaje p1) {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			if (j == p1.getPosX() && i == p1.getPosY()) {
				cout << "K ";
			}
			//else if (j == p2.getPosX() && i == p2.getPosY()) {
			//    cout << "D ";
			//}
			else {
				cout << "- ";
			}

		}
		cout << endl;
	}

	cout << endl;
}

void Game::posicionarEnemigos(Enemigo e[], int num, Personaje p, EnemigoFinal ef) {

	for (int i = 0; i < num; i++) {
		int hp = rand() % 100;
		string name = "Hechicero " + to_string(i + 1);
		int posX;
		int posY;

		do { // no han de coincidir con la casilla del heroe o del enemigoFinal
			posX = rand() % 10;
			posY = rand() % 5;
		} while ((posX == p.getPosX() && posY == p.getPosY()) || (posX == ef.getPosX() && posY == ef.getPosY()));

		e[i] = Enemigo(hp, 100, name, posX, posY);
	}
}

bool Game::checkCasilla(Personaje p1, int num, Enemigo p2[], EnemigoFinal p3) {

	if (p1.getPosX() == p3.getPosX() && p1.getPosY() == p3.getPosY()) {
		//cout << "Has encontrado la salida pero hay un enemigo tapandote el paso." << endl;
		//batalla(p1, p3);
		return true;

	}

	for (int i = 0; i < 3; i++) {
		if (p1.getPosX() == p2[i].getPosX() && p1.getPosY() == p2[i].getPosY()) {
			//cout << "Un enemigo te cierra el paso." << endl;
			//batalla(p1, p2[i]);
			return true;
		}
	}

	return false;

}

void Game::batalla(Personaje& p1, Personaje &p2) {
	int restaHP;
	while (p1.getHP() > 0 && p2.getHP() > 0) {
		// Turno del héroe

		int heroAttack = p1.getAttack();
		restaHP = p2.getHP() - heroAttack;
		p2.setHP(restaHP);

		if (p2.getHP() <= 0) {
			cout << "Has hecho " << -restaHP << " damage." << endl;
			cout << "Has matado al enemigo " << p2.getName() << endl;
			p2.setHP(0);

		}

		// Turno del enemigo
		int enemyAttack = p2.getAttack();
		restaHP = p1.getHP() - enemyAttack;
		p1.setHP(restaHP);

		// Verificar si el héroe fue derrotado
		if (p1.getHP() <= 0) {
			cout << "Te ha hecho " << restaHP << " damage." << endl;
			cout << "El enemigo " << p2.getName() << " te ha matado." << endl;
			p1.setHP(0);
		}
		
	}
}
