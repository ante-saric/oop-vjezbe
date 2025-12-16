#include "Player.h"

Player::Player(string name, int health):Gamecharacter(name, health), score(0){}

Player::~Player(){}

void Player::addScore(int points) {
	score += points;
}
