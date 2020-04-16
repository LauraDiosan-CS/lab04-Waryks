#pragma once
#include <ostream>
using namespace std;

class Carte {
private:
	char* author;
	char* title;
	int year;
	bool imprumut;
public:
	Carte();
	Carte(const char* author, const char* title, int year, bool imprumut);
	Carte(const Carte& c);
	~Carte();
	char* getAuthor();
	char* getTitle();
	int getYear();
	bool getImprumut();
	void setAuthor(const char* author);
	void setTitle(const char* title);
	void setYear(int year);
	void setImprumut(bool imprumut);
	Carte& operator=(const Carte& c);
	bool operator==(const Carte& c);
	bool operator<(const Carte& c);
	friend ostream& operator<<(ostream& os, const Carte& c);
};
