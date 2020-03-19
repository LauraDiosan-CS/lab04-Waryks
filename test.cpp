#include <iostream>
#include <assert.h>
#include "player.h"
#include "repo.h"

void testPlayer() {

	Player p(2312);
	assert(p.getNoWins() == 2312);
	Player p1 = p;
	assert(p1.getNoWins() == p.getNoWins());

}

void testRepo() {
	Repo repo;
	Player p1(321);
	Player p2(123);

	repo.addPlayer(p1);
	repo.addPlayer(p2);

	assert(repo.getNumberOfPlayers() == 2);
	assert(repo.getAllPlayers()[0].getNoWins() == p1.getNoWins());
	assert(repo.getAllPlayers()[1].getNoWins() == p2.getNoWins());
}

