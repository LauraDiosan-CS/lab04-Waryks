#include <iostream>
#include "repo.h"

Repo::Repo() {
	this->numPlayers = 0;
}

Repo::~Repo() {
	this->numPlayers = 0;
}

void Repo::addPlayer(Player& p) {
	this->players[this->numPlayers++] = p;
}

Player Repo::getPlayer(int pos) {
	return this->players[pos];
}

Player* Repo::getAllPlayers() {
	return this->players;
}

int Repo::getNumberOfPlayers() {
	return this->numPlayers;
}
