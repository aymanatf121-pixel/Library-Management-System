#include <iostream>
#include "AuthService.h"
#include "BookService.h"
#include "Member Service.h"
#include "BorrowingService.h"
#include "FineService.h"

using namespace std;
void memberMenu(MemberService &memberService)
{
    int choice;

    while (true)
    {
        cout << "\n===== Manage Members =====" << endl;

        cout << "1. Add Member" << endl;
        cout << "2. View Members" << endl;
        cout << "3. Search Member" << endl;
        cout << "4. Update Member" << endl;
        cout << "5. Delete Member" << endl;
        cout << "6. Back" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            memberService.addMember();
        }
        else if (choice == 2)
        {
            memberService.viewMembers();
        }
        else if (choice == 3)
        {
            memberService.searchMember();
        }
        else if (choice == 4)
        {
            memberService.updateMember();
        }
        else if (choice == 5)
        {
            memberService.deleteMember();
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
}

void mainMenu(BookService &bookService,
              MemberService &memberService,
              BorrowingService &borrowingService,
              FineService &fineService)
{
    int choice;

    while (true)
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====" << endl;

        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Update Book" << endl;
        cout << "5. Delete Book" << endl;
        cout << "6. Borrow Book" << endl;
        cout << "7. Return Book" << endl;
        cout << "8. Manage Members" << endl;
        cout << "9. Manage Fines" << endl;
        cout << "10. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            bookService.addBook();
        }
        else if (choice == 2)
        {
            bookService.viewBooks();
        }
        else if (choice == 3)
        {
            bookService.searchBook();
        }
        else if (choice == 4)
        {
            bookService.updateBook();
        }
        else if (choice == 5)
        {
            bookService.deleteBook();
        }
        else if (choice == 6)
        {
            borrowingService.borrowBook(bookService, memberService);
        }
        else if (choice == 7)
        {
            borrowingService.returnBook(bookService);
        }
        else if (choice == 8)
        {
            memberMenu(memberService);
        }
        else if (choice == 9)
        {
            fineService.viewFines();
        }
        else if (choice == 10)
        {
            cout << "Logged out successfully!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
}

int main()
{
    AuthService auth;
    BookService bookService;
    MemberService memberService;
    BorrowingService borrowingService;
    FineService fineService;

    int choice;

    while (true)
    {
        cout << "\n===== Welcome =====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            auth.registerUser();
        }
        else if (choice == 2)
        {
            if (auth.loginUser())
            {
                mainMenu(bookService,
                         memberService,
                         borrowingService,
                         fineService);
            }
        }
        else if (choice == 3)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
