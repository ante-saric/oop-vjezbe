#ifndef MAGE_H
#define MAGE_H
#include "Player.h"

class Mage :public Player {
protected:
	int mana;
public:
	Mage(string name);
	~Mage();
	void specialAbility()override;
	void attackEnemy(Enemy* target)override;
	void displayStatus()const override;
};


#endif // !MAGE_H
