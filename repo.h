#ifndef REPO_H
#define REPO_H
#include "player.h"

using namespace std;

class Repo {
private:
	Player players[50];
	int numPlayers;
public:
	Repo();
	~Repo();
	void addPlayer(Player& p);
	Player getPlayer(int position);
	Player* getAllPlayers();
	int getNumberOfPlayers();
};
#endif
