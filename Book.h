#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
public:
    int id;
    std::string title;
    std::string author;
    int quantity;

    Book(int i, std::string t, std::string a, int q)
    {
        id = i;
        title = t;
        author = a;
        quantity = q;
    }
};
#endif // BOOK_H
