#include <iostream>
#include <cstring>
#include "player.h"

using namespace std;

int Player::getNoWins() {
	return this->noWins;
}

void Player::setNoWins(int newNoWins) {
	this->noWins = newNoWins;
}

Player::Player(int numWin) {
	noWins = numWin;
}
Player::Player(const Player& p) {
	noWins = p.noWins;
}
Player::Player() {
	this->noWins = 0;

}
bool Player::compare(Player& p) {
	return ((this->noWins == p.noWins));
}
Player& Player::operator=(const Player& p) {
	this->setNoWins(p.noWins);
	return *this;
}
Player::~Player() {
    if(this->noWins)
		this->noWins = 0;
}
