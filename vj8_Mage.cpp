#include "Mage.h"
#include "Enemy.h"
#include <iostream>

Mage::Mage(string name):Player(name, 80), mana(100){}
Mage::~Mage() {}

void Mage::attackEnemy(Enemy* target) {
    if (!target || !target->isAlive()) return;

    if (mana >= 20) {
        target->takeDamage(40);
        mana -= 20;
    }
    else {
        target->takeDamage(20);
    }

    if (!target->isAlive())
        addScore(10);
}

void Mage::specialAbility() {
    if (mana > 50) {
        cout << name << "se teleprtitao" << endl;
    }
}

void Mage::displayStatus()const {
    cout << "Mage " << name
        << " | Health: " << health
        << " | Mana: " << mana
        << " | Score: " << score << endl;
}