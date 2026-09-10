#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n--- Registration ---\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Check duplicate username
    ifstream checkFile("users.txt");
    string savedUser, savedPass;

    while (checkFile >> savedUser >> savedPass)
    {
        if (savedUser == username)
        {
            cout << "Username already exists!\n";
            checkFile.close();
            return;
        }
    }

    checkFile.close();

    // Save user details
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string savedUser, savedPass;

    cout << "\n--- Login ---\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> savedUser >> savedPass)
    {
        if (savedUser == username && savedPass == password)
        {
            cout << "Login successful! Welcome, " << username << "!\n";
            file.close();
            return;
        }
    }

    file.close();

    cout << "Invalid username or password!\n";
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n============================\n";
        cout << " Login & Registration System\n";
        cout << "============================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}