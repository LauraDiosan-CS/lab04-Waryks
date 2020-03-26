#include <iostream>
#include <assert.h>
#include "player.h"
#include "repo.h"
#include "serv.h"
#include <cstring>

void testPlayer() {

	Player p(2312,10000,"Ghita");
	assert(p.getNoWins() == 2312);
	assert(p.getNoPlayed() == 10000);
	assert(strcmp(p.getName(),"Ghita")==0);
	Player p1 = p;
	assert(p1.getNoWins() == p.getNoWins());
	assert(p1.getNoPlayed() == p.getNoPlayed());
	assert(strcmp(p1.getName(),p.getName()) == 0);
}

void testRepo() {
	Repo repo;
	Player p1(321, 400, "Stef");
	Player p2(123, 400, "Alexa");

	repo.addPlayer(p1);
	repo.addPlayer(p2);

	assert(repo.getNumberOfPlayers() == 2);
	assert(repo.getAllPlayers()[0].getNoWins() == p1.getNoWins());
	assert(repo.getAllPlayers()[1].getNoWins() == p2.getNoWins());
}
void testService(){
    Repo repo;
    Player p1(4234, 600000, "Ghita");
	Player p2(21432, 600000, "Ion");
	repo.addPlayer(p1);
	repo.addPlayer(p2);
	Service serv(repo);
	serv.add_player(23123, 432523, "Mihai");
	assert(serv.getSizeRepo()==3);
	serv.remove_player("Mihai");
	assert(serv.getSizeRepo()==2);
}

