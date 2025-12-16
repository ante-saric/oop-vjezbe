#ifndef ENEMY_H
#define ENEMY_H
#include "Gamecharacter.h"
#include <string>

class Player;

class Enemy :public Gamecharacter {
protected:
	int difficulty;

public:
	Enemy(string name, int health, int difficulty);
	virtual ~Enemy();
	virtual void attackPlayer(Player* target) = 0;
};

#endif