#include "lancha.h"

lancha::lancha(float pSpeed, float pDistance, int pNitro, string pName) {
	speed = pSpeed;
	distance = pDistance;
	nitro = pNitro; //why = and not ==
	name = pName;
}

void lancha::updateSpeed(int newSpeed){
	speed += newSpeed;
}

void lancha::updateDistance(float newDistance) { //borrar, creo que no lo utilizo
	distance += newDistance;
}

void lancha::useNitro() {
	if (getNitro() == 1) { //el nitro esta disponible
		int n = rand() %  2; // acierto o error utilizarlo

		if (n == 1) { //acierto
			cout << "Lucky day your speed increased" << endl;
			speed = getSpeed() * 2;
			cout << "Your speed now is: " << getSpeed() << endl;
			setNitro(0);
			cout << endl;
		}
		else {
			cout << "Unlucky, your speed was reduced" << endl;
			speed = getSpeed() / 2;
			cout << "Your speed now is: " << getSpeed() << endl;
			setNitro(0);
			cout << endl;
		}
	}
	else {
		cout << "You don't have more nitro.\n" << endl;
	}
}

float lancha::calcDistance() {
	float dist;
	return dist = getDistance() + getSpeed() * 100;
}

void lancha::printStats() {
	cout << "-------STATS-------" << endl;
	cout << "Player: " << getName() << endl;
	cout << "Speed: " << getSpeed() << "km/h" << endl;
	cout << "Distance covered: " << getDistance() << "m" << endl;
	int nit = getNitro();
	if (nit == 1) {
		cout << "Nitro disponible" << endl;
	}
	else {
		cout << "Nitro NO disponible" << endl;
	}
	cout << "-------------------" << endl;
	cout << endl;
}