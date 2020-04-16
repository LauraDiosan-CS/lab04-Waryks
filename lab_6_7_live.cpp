#include "Repo.h"
#include "Carte.h"
#include "Test.h"
#include "Service.h"
#include "ui.h"
#include <iostream>

using namespace std;

int main()
{
    //tests();
    RepoSTL<Carte> repo("CarteIn.txt","CarteOut.txt");
    //RepoSTL<Carte> repo;
    Service serv(repo);
    Console c(serv);
    c.run();
    return 0;
}
