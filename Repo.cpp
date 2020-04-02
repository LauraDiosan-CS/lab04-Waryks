#include "Repo.h"
#include <fstream>

using namespace std;

RepoSTL::RepoSTL() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

RepoSTL::RepoSTL(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

RepoSTL::~RepoSTL()
{
	while(this->books.size() != 0)
		this->books.pop();
}

void RepoSTL::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoSTL::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void RepoSTL::addCarte(T c) {
	this->books.push(c);
	this->saveToFile();
}

queue<T> RepoSTL::getAll() {
	return this->books;
}

int RepoSTL::getSize()
{
	return this->books.size();
}
void RepoSTL::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		while (this->books.size() != 0)
			this->books.pop();
		ifstream f(this->fileNameIn);
		char* author = new char[20];
		char* title = new char[20];
		int year;
		while (!f.eof())
		{
			f >> author >> title >> year;
			if (strlen(author) > 0 && strlen(title) > 0)
			{
				this->addCarte(Carte(author, title, year));
			}
		}
		delete[] author;
		delete[] title;
		f.close();
	}
}

void RepoSTL::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->books.size(); i++)
		{
			f << this->books.front() << endl;
			books.pop();
		}
		f.close();
	}
}
