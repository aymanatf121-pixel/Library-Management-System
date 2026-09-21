#include "BookRepository.h"

void BookRepository::addBook(Book book)
{
    books.push_back(book);
}

std::vector<Book>& BookRepository::getAllBooks()
{
    return books;
}

Book* BookRepository::findBook(int id)
{
    for (Book &book : books)
    {
        if (book.id == id)
        {
            return &book;
        }
    }

    return nullptr;
}

bool BookRepository::deleteBook(int id)
{
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if (it->id == id)
        {
            books.erase(it);
            return true;
        }
    }

    return false;
}
