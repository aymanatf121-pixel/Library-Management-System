#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
public:
    string username;
    string password;

    User(string u, string p) {
        username = u;
        password = p;
    }
};

vector<User> users;

void registerUser() {
    string username;
    string password;

    cout << "\n===== Register =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    // Check if username already exists
    for (User user : users) {
        if (user.username == username) {
            cout << "Username already exists!" << endl;
            return;
        }
    }

    cout << "Enter password: ";
    cin >> password;

    if (password.empty()) {
        cout << "Password cannot be empty!" << endl;
        return;
    }

    users.push_back(User(username, password));

    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username;
    string password;

    cout << "\n===== Login =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    for (User user : users) {
        if (user.username == username && user.password == password) {
            cout << "Login successful!" << endl;
            return true;
        }
    }

    cout << "Invalid username or password!" << endl;
    return false;
}

void mainMenu() {
    int choice;

    cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====" << endl;

    cout << "1. Add Book" << endl;
    cout << "2. View Books" << endl;
    cout << "3. Search Book" << endl;
    cout << "4. Borrow Book" << endl;
    cout << "5. Return Book" << endl;
    cout << "6. Manage Members" << endl;
    cout << "7. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
}

int main() {

    int choice;

    while (true) {

        cout << "\n===== Welcome =====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            if (loginUser()) {
                mainMenu();
            }
        }
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}



