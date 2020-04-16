#pragma once
#include "service.h"
#include "Carte.h"
class Console {
private:
    Service s;
    void main_menu();
    char* read();
public:
    Console() {};
    Console(Service& service);
    ~Console() {};
    int run();

};