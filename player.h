#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Player{
private:
    int noWins, noPlayed;
    char* name;
public:
    int getNoWins();
    int getNoPlayed();
    char* getName();
    void setNoWins(int newNoWins);
    void setNoPlayed(int newNoPlayed);
    void setName(char* newName);
    Player();
    Player(int numWin,int numPlayed,char* pName);
    Player(const Player &p);
    bool compare(Player &p);
    Player& operator=(const Player& e);
    ~Player();
};

#endif // PLAYER_H
