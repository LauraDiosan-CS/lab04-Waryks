#include "serv.h"
#include "player.h"
#include <iostream>
#include <cstring>

using namespace std;

Player* Service::getAll(){
    return this->r.getAllPlayers();
}
int Service::getSizeRepo(){
    return this->r.getNumberOfPlayers();
}
Service::Service(Repo& repo)
{
    this -> r = repo;
}
void Service::add_player(int numWin,int numPlayed,char* pName){
    Player p = Player(numWin,numPlayed,pName);
    this-> r.addPlayer(p);
}
void Service::remove_player(char* pName){
    int len = this->r.getNumberOfPlayers();
    Player* player = this->r.getAllPlayers();
    for(int i=0; i<len; i++)
        if(strcmp(player[i].getName(),pName)==0)
        {
            this->r.deletePlayer(player[i]);
            i=len;
        }
}
void Service::update_player(char* p1Name, int n2Win, int n2Played, char* p2Name){
    int len = this->r.getNumberOfPlayers();
    Player* player = this->r.getAllPlayers();
    Player player2 = Player(n2Win,n2Played,p2Name);
    Player player1;
    for(int i=0; i<len; i++)
        if(strcmp(player[i].getName(),p1Name)==0)
        {
            player1 = player[i];
            i=len;
        }
    this -> r.updatePlayer(player1,player2);
}
