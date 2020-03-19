#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Player{
private:
    int noWins;
public:
    int getNoWins();
    void setNoWins(int newNoWins);
    Player();
    Player(int noWins);
    Player(const Player &p);
    bool compare(Player &p);
    Player& operator=(const Player& e);
    ~Player();
};

#endif // PLAYER_H
