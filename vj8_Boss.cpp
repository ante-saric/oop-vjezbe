#include "Boss.h"
#include "Player.h"
#include <iostream>

Boss::Boss(string name)
    : Enemy(name, 300, 8) {
    maxHealth = 300;
}

Boss::~Boss() {}

void Boss::attackPlayer(Player* target) {
    if (!target || !target->isAlive()) return;
    target->takeDamage(10 * difficulty);
}

void Boss::specialAbility() {
    health += 50;
    if (health > maxHealth)
        health = maxHealth;
    cout << name << " regenerates!" << endl;
}

void Boss::displayStatus() const {
    cout << "Boss " << name
        << " | Health: " << health
        << " | Difficulty: " << difficulty << endl;
}
