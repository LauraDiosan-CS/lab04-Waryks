#include "Service.h"
#include "Carte.h"
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

queue<Carte>* Service::getAll() {
    return this->r.getAll();
}
int Service::getSizeRepo() {
    return this->r.getSize();
}

void Service::add_book(char* author, char* title, int year, bool imp) {
    Carte p = Carte(author, title, year, imp);
    this->r.addCarte(p);
}
void Service::remove_book(char* author) {
    r.deleteItem(author);
}
void Service::update_book(char* author1, char* author2, char* title2, int year, bool imp) {
    //queue<Carte>* c = this->r.getAll();
    //queue<Carte>* aux = new queue<Carte>();
    Carte c2 = Carte(author2, title2, year, imp);
    /*Carte c1;
    for (int i = 0; i < c->size(); i++)
        if (strcmp(c->front().getAuthor(), author1) == 0)
        {
            c1 = c->front();
            aux->push(c->front());
            c->pop();
            break;
        }
    while(aux->size()!=0)
    {
        c->push(aux->front());
        aux->pop();
    }*/
    this->r.updateItem(author1, c2);
}
