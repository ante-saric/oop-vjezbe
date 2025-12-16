#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <string>
using namespace std;


class Gamecharacter {
protected:
	string name;
	int health;
	int maxHealth;
public:
	Gamecharacter(string name, int health);
	virtual ~Gamecharacter();
	virtual void displayStatus()const = 0;
	virtual void specialAbility() = 0;
	virtual void takeDamage(int amount);
	bool isAlive()const;

	string getName()const;
	int getHealth()const;

};
#endif GAMECHARACTER_H
