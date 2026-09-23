#include <iostream>
#include <limits>
#include "AuthService.h"
#include "BookService.h"
#include "Member Service.h"
#include "BorrowingService.h"
#include "FineService.h"
#include "AccountingService.h"
#include "AnalyticsService.h"

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

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

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

void fineMenu(FineService &fineService,
              AccountingService &accountingService,
              BorrowingService &borrowingService)
{
    int choice;

    while (true)
    {
        cout << "\n===== Manage Fines =====" << endl;

        cout << "1. Add Fine" << endl;
        cout << "2. View Fines" << endl;
        cout << "3. Search Fine" << endl;
        cout << "4. Update Fine" << endl;
        cout << "5. Delete Fine" << endl;
        cout << "6. Pay Fine" << endl;
        cout << "7. Back" << endl;

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

        if (choice == 1)
        {
            fineService.addFine(borrowingService);
        }
        else if (choice == 2)
        {
            fineService.viewFines();
        }
        else if (choice == 3)
        {
            fineService.searchFine();
        }
        else if (choice == 4)
        {
            fineService.updateFine();
        }
        else if (choice == 5)
        {
            fineService.deleteFine();
        }
        else if (choice == 6)
        {
            fineService.payFine(accountingService);
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
}

void analyticsMenu(
    AnalyticsService &analyticsService,
    BookService &bookService,
    MemberService &memberService,
    BorrowingService &borrowingService,
    AccountingService &accountingService)
{
    int choice;

    while (true)
    {
        cout << "\n===== Analytics =====" << endl;

        cout << "1. Most Borrowed Books" << endl;
        cout << "2. Most Active Members" << endl;
        cout << "3. Monthly Fine Revenue" << endl;
        cout << "4. Back" << endl;

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

        if (choice == 1)
        {
            analyticsService.showMostBorrowedBooks(
                bookService,
                borrowingService
            );
        }
        else if (choice == 2)
        {
            analyticsService.showMostActiveMembers(
                memberService,
                borrowingService
            );
        }
        else if (choice == 3)
        {
            analyticsService.showMonthlyFineRevenue(
                accountingService
            );
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
}

void mainMenu(
    BookService &bookService,
    MemberService &memberService,
    BorrowingService &borrowingService,
    FineService &fineService,
    AccountingService &accountingService,
    AnalyticsService &analyticsService)
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
        cout << "10. Accounting" << endl;
        cout << "11. Analytics" << endl;
        cout << "12. Logout" << endl;

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

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
            borrowingService.borrowBook(
                bookService,
                memberService
            );
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
            fineMenu(
                fineService,
                accountingService,
                borrowingService
            );
        }
        else if (choice == 10)
        {
            cout << "\n===== Accounting =====" << endl;

            cout << "1. View Transactions" << endl;
            cout << "2. View Revenue Report" << endl;
            cout << "3. Back" << endl;

            int accountingChoice;

            if (!(cin >> accountingChoice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input!" << endl;
                continue;
            }

            if (accountingChoice == 1)
            {
                accountingService.viewTransactions();
            }
            else if (accountingChoice == 2)
            {
                accountingService.viewRevenueReport();
            }
            else if (accountingChoice == 3)
            {
                continue;
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
        }
        else if (choice == 11)
        {
            analyticsMenu(
                analyticsService,
                bookService,
                memberService,
                borrowingService,
                accountingService
            );
        }
        else if (choice == 12)
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
    AccountingService accountingService;
    AnalyticsService analyticsService;

    int choice;

    while (true)
    {
        cout << "\n===== Welcome =====" << endl;

        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

        if (choice == 1)
        {
            auth.registerUser();
        }
        else if (choice == 2)
        {
            if (auth.loginUser())
            {
                mainMenu(
                    bookService,
                    memberService,
                    borrowingService,
                    fineService,
                    accountingService,
                    analyticsService
                );
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
