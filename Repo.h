#pragma once
#include "Carte.h"
#include <queue>

template <class T> class RepoSTL {
private:
	queue<T> books;
	char* fileNameIn;
	char* fileNameOut;
public:
	RepoSTL();
	RepoSTL(const char* fileNameIn, const char* fileNameOut);
	~RepoSTL();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameIOut);

	void addCarte(T c);
	queue<T> getAll();

	int getSize();
	void loadFromFile();
	void saveToFile();
};
