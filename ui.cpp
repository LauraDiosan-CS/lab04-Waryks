#include <iostream>
#include "Carte.h"
#include "test.h"
#include "repo.h"
#include "ui.h"
#include <string.h>

using namespace std;

Console::Console(Service& service) {
    this->s = service;
}

void Console::main_menu()
{
    cout << "1. Add a book" << endl;
    cout << "2. Modify a book" << endl;
    cout << "3. Delete a book" << endl;
    cout << "4. Show all books" << endl;
    cout << "5. Borrow book(s)" << endl;
    cout << "6. Return book(s)" << endl;
}
char* Console::read()
{
    char b[100];
    cin >> b;
    char* a = new char[strlen(b) + 1];
    strcpy_s(a, strlen(b) + 1, b);
    return a;
}

int Console::run()
{
    int op = 0;
    bool work = 0;
    while (work == 0)
    {
        this->main_menu();
        cin >> op;
        if (op == 1)
        {
            cout << "Name of the author: ";
            char* a = this->read();
            cout << "Title of the book: ";
            char* b = this->read();
            cout << "Write year: ";
            int year;
            cin >> year;
            this->s.add_book(a, b, year, false);
        }
        else if (op == 2)
        {
            cout << "The name of the author that u wish to modify: ";
            char* a1 = this->read();
            cout << "The new name of the author: ";
            char* a2 = this->read();
            cout << "Title of the book: ";
            char* b2 = this->read();
            cout << "Year that the book was published on: ";
            int year;
            cin >> year;
            this->s.update_book(a1, a2, b2, year, false);

        }
        else if (op == 3)
        {
            cout << "The name of the author that u wish to delete: ";
            char* player = this->read();
            this->s.remove_book(player);
        }
        else if (op == 4)
        {
            queue<Carte>* carti = s.getAll();
            queue<Carte>* aux = new queue<Carte>();
            while (carti->size() != 0)
            {
                cout << carti->front() << '\n';
                aux->push(carti->front());
                carti->pop();
            }
            while (aux->size() != 0)
            {
                carti->push(aux->front());
                aux->pop();
            }
        }
        else if (op == 5)
        {
            cout << "Name of the author: ";
            char* author = this->read();
            cout << "Title of the book: ";
            char* title = this->read();
            queue<Carte>* carti = s.getAll();
            queue<Carte>* aux = new queue<Carte> ();
            for (int i = 0; i < carti->size(); i++)
            {
                if (strcmp(carti->front().getAuthor(), author) == 0 && strcmp(carti->front().getTitle(), title) == 0)
                {
                    if (carti->front().getImprumut() == false)
                    {
                        cout << "Book has been borrowed succesfully!" << '\n';
                        carti->front().setImprumut(true);
                    }
                    else
                        cout << "Book has been borrowed already!" << '\n';
                    break;
                }
                aux->push(carti->front());
                carti->pop();
            }
            while (aux->size() != 0)
            {
                carti->push(aux->front());
                aux->pop();
            }
        }
        else if (op == 6)
        {
            cout << "Name of the author: ";
            char* author = this->read();
            cout << "Title of the book: ";
            char* title = this->read();
            queue<Carte>* carti = s.getAll();
            queue<Carte>* aux = new queue<Carte>();
            for (int i = 0; i < carti->size(); i++)
            {
                if (strcmp(carti->front().getAuthor(), author) == 0 && strcmp(carti->front().getTitle(), title) == 0)
                {
                    if (carti->front().getImprumut() == true)
                    {
                        cout << "Book has been returned succesfully!" << '\n';
                        carti->front().setImprumut(false);
                    }
                    else
                        cout << "Book has not been borrowed!" << '\n';
                    break;
                }
                aux->push(carti->front());
                carti->pop();
            }
            while (aux->size() != 0)
            {
                carti->push(aux->front());
                aux->pop();
            }
        }
        else
            return 0;
    }
}
