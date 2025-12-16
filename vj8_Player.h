#ifndef PLAYER_H
#define PLAYER_H

#include "Gamecharacter.h"
#include <string>
using namespace std;

class Enemy;

class Player:public Gamecharacter {
protected:
	int score;
public :
	Player(string name, int health);
	virtual ~Player();
	virtual void attackEnemy(Enemy* target) = 0;
	void addScore(int points);
};




#endif 
