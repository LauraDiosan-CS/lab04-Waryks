#include "Carte.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Carte::Carte() {
	this->author = NULL;
	this->title = NULL;
	this->year= 0;
	this->imprumut = false;
}

Carte::Carte(const char* author, const char* title, int year, bool imprumut)
{
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, 1 + strlen(author), author);
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, 1 + strlen(title), title);
	this->year = year;
	this->imprumut = imprumut;
}

Carte::Carte(const Carte& c) {
	this->author = new char[strlen(c.author) + 1];
	strcpy_s(this->author, 1 + strlen(c.author), c.author);
	this->title = new char[strlen(c.title) + 1];
	strcpy_s(this->title, 1 + strlen(c.title), c.title);
	this->year = c.year;
	this->imprumut = c.imprumut;
}

Carte::~Carte() {
	if (this->author) {
		delete[] this->author;
		this->author = NULL;
	}
	if (this->title) {
		delete[] this->title;
		this->title = NULL;
	}
	this->year = 0;
	this->imprumut = false;
}

char* Carte::getAuthor() {
	return this->author;
}

char* Carte::getTitle() {
	return this->title;
}

int Carte::getYear() {
	return this->year;
}
bool Carte::getImprumut() {
	return this->imprumut;
}
void Carte::setAuthor(const char* author)
{
	if (this->author) {
		delete[] this->author;
	}
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
}
void Carte::setTitle(const char* title)
{
	if (this->title) {
		delete[] this->title;
	}
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
}

void Carte::setYear(int year) {
	this->year = year;
}

void Carte::setImprumut(bool imprumut) {
	this->imprumut = imprumut;
}

Carte& Carte::operator=(const Carte& c) {
	this->setAuthor(c.author);
	this->setTitle(c.title);
	this->setYear(c.year);
	return *this;
}

bool Carte::operator==(const Carte& c) {
	return strcmp(this->author, c.author) == 0 && strcmp(this->title, c.title) == 0 && this->year == c.year;
}

ostream& operator<<(ostream& os, const Carte& c)
{
	os << c.author << " " << c.title << " " << c.year << " " << c.imprumut;
	return os;
}
bool Carte::operator<(const Carte& c)
{
	return (this->year < c.year);
}