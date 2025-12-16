#include "Gamecharacter.h"
#include <iostream>

Gamecharacter::Gamecharacter(string name, int health) :name(name), health(health), maxHealth(health){}
Gamecharacter::~Gamecharacter() {}

void Gamecharacter::takeDamage(int amount) {
	health -= amount;
	if (health < 0)health = 0;
}

bool Gamecharacter::isAlive()const {
	return health > 0;
}

string Gamecharacter::getName()const {
	return name;
}

int Gamecharacter::getHealth()const {
	return health;
}

