#pragma once
#include <ostream>
using namespace std;

class Carte {
private:
	char* author;
	char* title;
	int year;
public:
	Carte();
	Carte(const char* author, const char* title, int year);
	Carte(const Carte& c);
	~Carte();
	char* getAuthor();
	char* getTitle();
	int getYear();
	void setAuthor(const char* author);
	void setTitle(const char* title);
	void setYear(int year);
	Carte& operator=(const Carte& c);
	bool operator==(const Carte& c);
	friend ostream& operator<<(ostream& os, const Carte& c);
};
