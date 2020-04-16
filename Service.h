#pragma once
#include "Carte.h"
#include "Repo.h"
#include <iostream>
class Service {
    RepoSTL<Carte> r;
public:
    Service() {};
    Service(RepoSTL<Carte> repo) { this->r = repo; };
    ~Service() {};
    void add_book(char* author, char* title,int year, bool imp);
    void remove_book(char* author);
    void update_book(char* author1, char* author2, char* title2, int year2, bool imp);
    queue<Carte>* getAll();
    int getSizeRepo();
};