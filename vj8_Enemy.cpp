#include "Enemy.h"

Enemy::Enemy(string name, int health, int difficulty) : Gamecharacter(name, health), difficulty(difficulty) {};
Enemy::~Enemy(){}
