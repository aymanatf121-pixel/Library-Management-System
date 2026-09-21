#include "include/BookService.h"
#include "InputValidator.h"
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

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Book ID!" << endl;
        return;
    }

    if (bookExists(id))
    {
        cout << "Book ID already exists!" << endl;
        return;
    }

    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);

    if (!InputValidator::isNotEmpty(title))
    {
        cout << "Book title cannot be empty!" << endl;
        return;
    }

    cout << "Enter Author Name: ";
    getline(cin, author);

    if (!InputValidator::isNotEmpty(author))
    {
        cout << "Author name cannot be empty!" << endl;
        return;
    }

    cout << "Enter Quantity: ";

    if (!InputValidator::readNonNegativeInt(quantity))
    {
        cout << "Invalid quantity!" << endl;
        return;
    }

    BookRepository.addBook(Book(id, title, author, quantity));

    cout << "Book added successfully!" << endl;
}

void BookService::viewBooks()
{
    cout << "\n===== Books List =====" << endl;

    if (BookRepository.getAllBooks().empty())
    {
        cout << "No books available." << endl;
        return;
    }

    for (Book book : BookRepository.getAllBooks())
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

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Book ID!" << endl;
        return;
    }

    Book* book = BookRepository.findBook(id);

    if (book != nullptr)
    {
        cout << "Book found!" << endl;
        cout << "Title: " << book->title << endl;
        cout << "Author: " << book->author << endl;
        cout << "Quantity: " << book->quantity << endl;
        return;
    }

    cout << "Book not found!" << endl;
}

void BookService::updateBook()
{
    int id;

    cout << "\n===== Update Book =====" << endl;

    cout << "Enter Book ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Book ID!" << endl;
        return;
    }

    Book* book = BookRepository.findBook(id);

    if (book == nullptr)
    {
        cout << "Book not found!" << endl;
        return;
    }

    string newTitle;
    string newAuthor;
    int newQuantity;

    cout << "Enter new title: ";
    cin.ignore();
    getline(cin, newTitle);

    if (!InputValidator::isNotEmpty(newTitle))
    {
        cout << "Book title cannot be empty!" << endl;
        return;
    }

    cout << "Enter new author: ";
    getline(cin, newAuthor);

    if (!InputValidator::isNotEmpty(newAuthor))
    {
        cout << "Author name cannot be empty!" << endl;
        return;
    }

    cout << "Enter new quantity: ";

    if (!InputValidator::readNonNegativeInt(newQuantity))
    {
        cout << "Invalid quantity!" << endl;
        return;
    }

    book->title = newTitle;
    book->author = newAuthor;
    book->quantity = newQuantity;

    cout << "Book updated successfully!" << endl;
}

void BookService::deleteBook()
{
    int id;

    cout << "\n===== Delete Book =====" << endl;

    cout << "Enter Book ID: ";

    if (!InputValidator::readPositiveInt(id))
    {
        cout << "Invalid Book ID!" << endl;
        return;
    }

    if (BookRepository.deleteBook(id))
    {
        cout << "Book deleted successfully!" << endl;
        return;
    }

    cout << "Book not found!" << endl;
}

bool BookService::bookExists(int id)
{
    return BookRepository.findBook(id) != nullptr;
}

bool BookService::decreaseQuantity(int id)
{
    Book* book = BookRepository.findBook(id);

    if (book != nullptr && book->quantity > 0)
    {
        book->quantity--;
        return true;
    }

    return false;
}

bool BookService::increaseQuantity(int id)
{
    Book* book = BookRepository.findBook(id);

    if (book != nullptr)
    {
        book->quantity++;
        return true;
    }

    return false;
}
