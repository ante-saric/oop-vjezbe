#ifndef WARRIOR_H
#define WARRRIOR_H
#include "Player.h"
class Warrior :public Player {
protected:
	bool shieldActivated;
public:
	Warrior(string name);
	~Warrior();

	void attackEnemy(Enemy* target)override;
	void displayStatus()const override;
	void specialAbility()override;

	void takeDamage(int amount)override;
};

#endif 