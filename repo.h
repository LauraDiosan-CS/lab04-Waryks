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
	void addPlayer(Player p);
	Player getPlayer(int position);
	Player* getAllPlayers();
	int getNumberOfPlayers();
	void deletePlayer(Player& p);
	void updatePlayer(Player& p1, Player& p2);
};
#endif
