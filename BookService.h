#ifndef BOOKSERVICE_H
#define BOOKSERVICE_H
#include "Book.h"
#include <vector>

using namespace std;

class BookService
{
private:
    vector<Book> books;

public:
    void addBook();
    void viewBooks();
    void searchBook();
    void updateBook();
    void deleteBook();
};

#endif // BOOKSERVICE_H
