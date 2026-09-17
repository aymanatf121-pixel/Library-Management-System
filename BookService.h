#ifndef BOOKSERVICE_H
#define BOOKSERVICE_H

#include "Book.h"
#include <vector>

class BookService
{
private:
    std::vector<Book> books;

public:
    void addBook();
    void viewBooks();
    void searchBook();
    void updateBook();
    void deleteBook();

    bool bookExists(int id);
    bool decreaseQuantity(int id);
    bool increaseQuantity(int id);
};

#endif // BOOKSERVICE_H
