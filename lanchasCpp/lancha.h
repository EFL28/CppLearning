#pragma once
#include <iostream>

using namespace std;

class lancha
{
	public:
		//constructors
		lancha(float pSpeed, float pDistance, int pNitro, string pName);

		//getters
		float getSpeed() { return speed; }
		float getDistance() { return distance; }
		int getNitro() { return nitro; }
		string getName() { return name; }

		//setters
		void setSpeed(float pSpeed) { speed = pSpeed; }
		void setDistance(float pDistance) { distance = pDistance; }
		void setNitro(int pNitro) { nitro = pNitro; } //why = and not ==
		void setName(string pName) { name = pName; }

		//methods
		void updateSpeed(int newSpeed);
		float calcDistance();
		void updateDistance(float newDistance);
		void useNitro();
		void printStats();

	private:
		//attributes
		float speed;
		float distance;
		int nitro;
		string name;
};

