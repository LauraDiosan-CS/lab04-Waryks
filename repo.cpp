#include <iostream>
#include "repo.h"
#include <cstring>

Repo::Repo() {
	this->numPlayers = 0;
}

Repo::~Repo() {
	this->numPlayers = 0;
}

void Repo::addPlayer(Player p) {
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
void Repo::deletePlayer(Player& p){
    int len = this ->getNumberOfPlayers();
    if(len == 1)
        this->numPlayers = 0;
    else
    {
        Player* players = this->getAllPlayers();
        for(int i=0; i<len; i++)
        {
            if(strcmp(players[i].getName(),p.getName())==0)
                len--;
                for(int j=i; j<len; j++)
                    players[j]=players[j+1];
                break;
        }
        this -> numPlayers = len;
    }
}
void Repo::updatePlayer(Player& p1,Player& p2){
    int len = this ->getNumberOfPlayers();
    Player* players = this->getAllPlayers();
    for(int i=0; i<len; i++)
        if(strcmp(players[i].getName(),p1.getName())==0)
            players[i] = p2;
}
