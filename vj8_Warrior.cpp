#include "Warrior.h"
#include "Enemy.h"
#include <iostream>

Warrior::Warrior(string name) :Player(name, 120), shieldActivated(false) {}
Warrior::~Warrior(){}

void Warrior::attackEnemy(Enemy* target){
	if (!target || !target->isAlive())return;
	target->takeDamage(20);
	if (!target->isAlive()) {
		addScore(10);
	}
}


void Warrior::specialAbility() {
	shieldActivated = true;
	cout << name << " shield activated!!" << endl;

}


void Warrior::takeDamage(int amount) {
	if (shieldActivated) {
		amount / 2;
		shieldActivated = false;
	}
	Gamecharacter::takeDamage(amount);
}

void Warrior::displayStatus() const {
	cout << "Warrior " << name
		<< " | Health: " << health
		<< " | Score: " << score << endl;
}