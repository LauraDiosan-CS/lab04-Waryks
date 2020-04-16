#pragma once
#include "Carte.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;

template <class T> 
class RepoSTL {
private:
	queue<T>* books;
	char* fileNameOut;
	char* fileNameIn;
public:
	RepoSTL() {
		this->books = new queue<T>();
		this->fileNameOut = NULL;
		this->fileNameIn = NULL;
	}
	RepoSTL(RepoSTL<T>& repo) {
		this->books = repo.books;
		this->fileNameOut = repo.fileNameOut;
		this->fileNameIn = repo.fileNameIn;
	}
	RepoSTL<T>& operator=(RepoSTL<T>& repo)
	{
		this->books = repo.books;
		this->fileNameOut = repo.fileNameOut;
		this->fileNameIn = repo.fileNameIn;
		return *this;
	}
	RepoSTL(const char* fileNameIn,const char* fileNameOut) {
		this->books = new queue<T>();
		this->fileNameOut = new char[strlen(fileNameOut) + 1];
		strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
		this->fileNameIn = new char[strlen(fileNameIn) + 1];
		strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
		this->loadFromFile();
	}
	~RepoSTL() {
		while (this->books->size() != 0)
			this->books->pop();
		if (this->fileNameOut)
			delete[] this->fileNameOut;
		this->fileNameOut = NULL;
		if (this->fileNameIn)
			delete[] this->fileNameIn;
		this->fileNameIn = NULL;
	}
	void addCarte(T s) { 
		this->books->push(s);
		this->saveToFile();
	}
	queue<T>* getAll() {
		return this->books;
	}
	int getSize() {
		return this->books->size();
	}
	void deleteItem(char* name) {
		queue<T>* elem = this->getAll();
		queue<T>* aux = new queue<T>();
		int ok = 0;
		for (int i = 0; i < elem->size(); i++)
		{
			if (strcmp(elem->front().getAuthor(), name) != 0)
			{
				aux->push(elem->front());
				elem->pop();
			}
			else
			{
				elem->pop();
				while (aux->size() != 0)
				{
					elem->push(aux->front());
					aux->pop();
				}
				ok = 1;
				break;
			}
		}
		if (!ok)
			while (aux->size() != 0)
			{
				elem->push(aux->front());
				aux->pop();
			}
		this->saveToFile();
	}
	void updateItem(char* name, T& p2) {
		queue<T>* elem = this->getAll();
		queue<T>* aux = new queue<T>();
		int ok = 0;
		for (int i = 0; i < elem->size(); i++)
			if (strcmp(elem->front().getAuthor(), name) != 0)
			{
				aux->push(elem->front());
				elem->pop();
			}
			else
			{
				elem->front() = p2;
				while (aux->size() != 0)
				{
					elem->push(aux->front());
					aux->pop();
				}
				ok = 1;
				break;
			}
		if(!ok)
			while (aux->size() != 0)
			{
				elem->push(aux->front());
				aux->pop();
			}
		this->saveToFile();
	}
	void loadFromFile() {
		ifstream f(this->fileNameIn);
		if (this->fileNameIn != NULL)
		{
			char* author = new char[20];
			char* title = new char[20];
			int year;
			bool imprumut;
			while (!f.eof())
			{
				f >> author >> title >> year >> imprumut;
				Carte c;
				c = Carte(author, title, year, imprumut);
				this->books->push(c);
			}
			delete[] author;
			delete[] title;
			f.close();
		}
	}
	void saveToFile() {
		if (this->fileNameOut != NULL)
		{
			ofstream g(this->fileNameOut);
			queue<T>* elem = this->books;
			queue<T>* aux = new queue<T>();
			int len = elem->size();
			for (int i = 0; i < len; i++)
			{
				cout << elem->front() << '\n';
				g << elem->front() << endl;
				aux->push(elem->front());
				elem->pop();
			}
			while (aux->size() != 0)
			{
				elem->push(aux->front());
				aux->pop();
			}
			g.close();
		}
	}

};
