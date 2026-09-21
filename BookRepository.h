
#ifndef BOOKREPOSITORY_H
#define BOOKREPOSITORY_H

#include "Book.h"
#include <vector>


class BookRepository
{
private:
    std::vector<Book> books;

public:
    void addBook(Book book);
    std::vector<Book>& getAllBooks();
    Book* findBook(int id);
    bool deleteBook(int id);
};

#endif // BOOKREPOSITORY_H
