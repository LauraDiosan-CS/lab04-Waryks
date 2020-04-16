#include "Carte.h"
#include "Repo.h"
#include <assert.h>
#include <iostream>

void tests()
{
	{
		Carte e = Carte("Minulescu","Ion", 1999, false);
		Carte e2 = Carte("Stanescu", "Gheorghe", 1934, false);
		assert(e.getYear() == 1999);
		assert(strcmp(e.getAuthor(), "Minulescu")==0);
		assert(strcmp(e.getTitle(), "Ion") == 0);
		assert(e == e);
		RepoSTL<Carte> rep;
		assert(rep.getAll()->size() == 0);
		rep.addCarte(e);
		assert(rep.getAll()->size() == 1);
		rep.addCarte(e2);
		assert(rep.getAll()->size() == 2);
	}
}