#include <iostream>
#include <cstddef>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"

using namespace std;

int Player::getNoWins() {
	return this->noWins;
}
int Player::getNoPlayed(){
    return this->noPlayed;
}
char* Player::getName(){
    return this->name;
}

void Player::setNoWins(int newNoWins) {
	this->noWins = newNoWins;
}
void Player::setNoPlayed(int newNoPlayed){
    this->noPlayed = newNoPlayed;
}
void Player::setName(char* newName){
    if(this->name)
        delete[] this->name;
    this->name = new char[strlen(newName)+1];
    strcpy(this->name,newName);
}

Player::Player(int numWin,int numPlayed,char* pName) {
	this->noWins = numWin;
	this->noPlayed = numPlayed;
	this->name = new char(strlen(pName)+1);
	strcpy(this->name,pName);
}
Player::Player(const Player& p) {
	this->noWins = p.noWins;
	this->noPlayed = p.noPlayed;
	if(this->name)
        delete[] this->name;
    this->name = new char(strlen(p.name)+1);
    strcpy(this->name,p.name);
}
Player::Player() {
	this->noWins = 0;
    this->noPlayed = 0;
    if (this->name)
		delete[] this->name;
    this->name = NULL;
}
bool Player::compare(Player& p) {
	return ((this->noWins == p.noWins && this->noPlayed == p.noPlayed && strcmp(this->name,p.name)==0));
}
Player& Player::operator=(const Player& p) {
	this->setNoWins(p.noWins);
	this->setNoPlayed(p.noPlayed);
	this->setName(p.name);
	return *this;
}
Player::~Player() {
    this->noWins = 0;
    this->noPlayed = 0;
    if (this->name)
		delete[] this->name;
    this->name = NULL;
}
