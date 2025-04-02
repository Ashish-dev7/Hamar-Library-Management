#include <iostream>
#include "Functions.h"
using namespace std;


void Screen()
{
    cout << "\033[2J\033[H"; // ANSI escape codes to clear screen
}

void Lib()
{
wrong:
    cout << "=====================================================\n";
    cout << "         This is admin panel for Librarian\n";
    cout << "=====================================================\n\n";

    string admin;
    string passwd;
    cout << "               Enter Username : ";
    cin >> admin;
    cout << "               Enter Password : ";
    cin >> passwd;
    Screen();

    if (admin == "root" && passwd == "passwd")
    {
        Add();
    }
    else
    {
        cout << "Wrong User Credentials!!!\n";
        cout << "User Not Found!!\n";
        cout << "Enter User Id and Password again!\n\n";
        goto wrong;
    }
}

