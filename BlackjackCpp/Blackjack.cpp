#include <iostream>
using namespace std;

//Variables globales

//Jugador1
string P1_name = "Elian"; //pedir nombre
int P1_points = 0;
bool P1_finish = false;
bool P1_winner = false;
bool P1_loser = false;

//Jugador2
string P2_name = "Banca";
int P2_points = 0;
bool P2_finish = false;
bool P2_winner = false;
bool P2_loser = false;

//Game
int picas[13];
int treboles[13];
int corazones[13];
int diamantes[13]; //(Indice = carta, indice + 1 = valor carta)

void inicializeArray(int(&array)[13]) { //todos los indices a 1, marcan que estan disponibilidad para ser repartidas.
	for (int i = 0; i < 13; i++) {
		array[i] = 1;
	}
}

void handOutCards(string player_name, int& player_points) {
	bool escogida = false;
	int option;
	int indexCarta = 0;
	int suit_num;
	string suit_name;

	while (!escogida) {
		indexCarta = rand() % 13; //se selecciona una carta random entre 0-12 (13 cartas)
		suit_num = rand() % 4; //se selecciona un palo de carta random entre 0-3 (4 palos)

		switch (suit_num) {
		case 0:
			if (picas[indexCarta] == 1) { //comprobamos si la carta esta disponible en el palo
				picas[indexCarta] = 0;
				suit_name = "Picas";
				escogida = true;
			}
			break;
		case 1:
			if (treboles[indexCarta] == 1) { //comprobamos si la carta esta disponible en el palo
				treboles[indexCarta] = 0;
				suit_name = "Treboles";
				escogida = true;
			}
			break;
		case 2:
			if (corazones[indexCarta] == 1) { //comprobamos si la carta esta disponible en el palo
				corazones[indexCarta] = 0;
				suit_name = "Corazones";
				escogida = true;
			}
			break;
		case 3:
			if (diamantes[indexCarta] == 1) { //comprobamos si la carta esta disponible en el palo
				diamantes[indexCarta] = 0;
				suit_name = "Diamantes";
				escogida = true;
			}
			break;
		default:
			break;
		}
	}

	switch (indexCarta + 1) { //index + 1 = valor carta
	case 1:
		if (player_name == P1_name) {
			cout << "Te ha salido un As, cual es el valor que quieres darle: " << endl;
			cout << "1.- As con valor 1." << endl;
			cout << "11.- As con valor 11." << endl;

			cin >> option;

			if (option == 1) //dependiendo lo que quiera el jugador el as valdra 1 o 11
				player_points += indexCarta + 1;
			else
				player_points += indexCarta + 11;
		}
		else { //si es la banca cogera la mejor opcion
			if (player_points + 11 > 21) {
				player_points += 1;
			}
			else {
				player_points += 11;
			}
		}
		cout << "El jugador " << player_name << " ha sacado un As de " << suit_name << endl;
		break;
	case 11: //valor J = 10
		player_points += 10;
		cout << "El jugador " << player_name << " ha sacado una J de " << suit_name << endl;
		break;
	case 12:
		player_points += 10; //valor Q = 10
		cout << "El jugador " << player_name << " ha sacado una Q de " << suit_name << endl;
		break;
	case 13:
		player_points += 10; //valor K = 10
		cout << "El jugador " << player_name << " ha sacado una K de " << suit_name << endl;
		break;
	default: //de 2 a 10 valdra lo que vale el index + 1
		player_points += indexCarta + 1;
		cout << "El jugador " << player_name << " ha sacado un " << indexCarta + 1 << " de " << suit_name << endl;
		break;
	}
	cout << "El jugador tiene: " << player_points << " puntos.\n" << endl;
}

void handCheck(int& points, bool& finish, bool& win, bool& loose) { //si el jugador tiene =21p o >21p -> salta turno
	if (points == 21) {
		win = true;
		finish = true;
	}
	else if (points > 21) {
		loose = true;
		finish = true;
	}
}

void checkWinner(int P1points, int P2points, bool& P1win, bool& P2win, bool& P2finish, bool& P1lose) {
	if (P2points > P1points && P2points <= 21) { //P2 no se pasa y tiene mas puntos que P1 ->
		P2win = true; //P2 gana
		P1lose = true; //P1 pierde
		P2finish = true; //cierra bucle P2
	}
	else if (P2points > P1points && P2points > 21) { //P2 se pasa de 21p
		P1win = true;
		P2finish = true;
	}
	else if (P2points == P1points && P2points == 21) { //P1 y P2 =21p -> ninguno gana
		P2win = false;
		P1win = false;
		P2finish = true;
	}
}

int main() {

	srand(time(NULL));

	//Inicializar baraja
	inicializeArray(picas);
	inicializeArray(treboles);
	inicializeArray(corazones);
	inicializeArray(diamantes);

	//Reparte 2 cartas al jugador, 1 para el croupier
	handOutCards(P1_name, P1_points);
	handOutCards(P2_name, P2_points);
	handOutCards(P1_name, P1_points);

	//Check mano del jugador P1
	handCheck(P1_points, P1_finish, P1_winner, P1_loser); 

	while (!P1_finish) { //mientras P1 no llegue a 21p
		int opcion = 0;
		while (opcion != 1 && opcion != 2) {
			cout << "Tienes: " << P1_points << " puntos." << endl;
			cout << "Selecciona que quieres hacer:\n";
			cout << "1. Pedir otra carta." << endl;
			cout << "2. Plantarte." << endl;

			cin >> opcion;

			if (opcion != 1 && opcion != 2) { //opcion incorrecta
				cout << "Opcion incorrecta, vuelve a introducir una opcion valida.\n" << endl;
			}
		}
		if (opcion == 1) { //pide carta -> se reparte y checkea puntos 
			handOutCards(P1_name, P1_points);
			handCheck(P1_points, P1_finish, P1_winner, P1_loser);

			if (P1_loser) { //nueva carta -> >21p 
				P2_winner = true; //P2 gana
				P2_finish = true; //evita entrar en bucle de P2
			}
		}
		else { //P1 no pide carta, acaba el turno de P1
			cout << "Tu turno ha finalizado. Tienes " << P1_points << " puntos. Ahora es el turno de " << P2_name <<".\n" << endl;
			P1_finish = true; //cierre P1 bucle
		}
	}

	while (!P2_finish) { // turno P2 -> mientras no llegue a 21p
		handOutCards(P2_name, P2_points); //pide carta
		handCheck(P2_points, P2_finish, P2_winner, P2_loser); //check puntos
		checkWinner(P1_points, P2_points, P1_winner, P2_winner, P2_finish, P1_loser); //en caso de P1 plantarse comprueba quie gana
	}

	if (P1_winner) {
		cout << "Resultado: Jugador " << P1_name << " ha ganado.\n";
	}
	else if (P2_winner) {
		cout << "Resultado: Jugador " << P2_name << " ha ganado.\n";
	}
	else {
		cout << "Resultado: Empate\n";
	}
}
