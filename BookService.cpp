#include "include/BookService.h"
#include <iostream>
#include <string>

using namespace std;

void BookService::addBook()
{
    int id;
    string title;
    string author;
    int quantity;

    cout << "\n===== Add Book =====" << endl;

    cout << "Enter Book ID: ";
    cin >> id;

    cout << "Enter Book Title: ";
    cin >> title;

    cout << "Enter Author Name: ";
    cin >> author;

    cout << "Enter Quantity: ";
    cin >> quantity;

    if (quantity < 0)
    {
        cout << "Quantity cannot be negative!" << endl;
        return;
    }

    books.push_back(Book(id, title, author, quantity));

    cout << "Book added successfully!" << endl;
}

void BookService::viewBooks()
{
    cout << "\n===== Books List =====" << endl;

    if (books.empty())
    {
        cout << "No books available." << endl;
        return;
    }

    for (Book book : books)
    {
        cout << "ID: " << book.id << endl;
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Quantity: " << book.quantity << endl;
        cout << "------------------------" << endl;
    }
}

void BookService::searchBook()
{
    int id;

    cout << "\n===== Search Book =====" << endl;
    cout << "Enter Book ID: ";
    cin >> id;

    for (Book book : books)
    {
        if (book.id == id)
        {
            cout << "Book found!" << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Quantity: " << book.quantity << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void BookService::updateBook()
{
    int id;

    cout << "\n===== Update Book =====" << endl;
    cout << "Enter Book ID: ";
    cin >> id;

    for (Book &book : books)
    {
        if (book.id == id)
        {
            cout << "Enter new title: ";
            cin >> book.title;

            cout << "Enter new author: ";
            cin >> book.author;

            cout << "Enter new quantity: ";
            cin >> book.quantity;

            if (book.quantity < 0)
            {
                cout << "Quantity cannot be negative!" << endl;
                return;
            }

            cout << "Book updated successfully!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void BookService::deleteBook()
{
    int id;

    cout << "\n===== Delete Book =====" << endl;
    cout << "Enter Book ID: ";
    cin >> id;

    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if (it->id == id)
        {
            books.erase(it);
            cout << "Book deleted successfully!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}
