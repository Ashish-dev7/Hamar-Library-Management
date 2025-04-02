#include <iostream>
#include <fstream>
#include <string>
#include "Librarian.h"
#include "readPasswords.h"

using namespace std;
void userCredentials();
void clearScreen()
{
     cout << "\033[2J\033[H"; // ANSI escape codes to clear screen
}
void students()
{
student:
     cout << endl;
     cout << "===========================================\n";
     cout << "Press 1 for login as a existing student\n";
     cout << "Press 2 for new students\n";
     cout << "===========================================\n";

     int studentid;
     cin >> studentid;
     clearScreen();

     if (studentid == 1)
     {

          string username, password;

          cout << "Enter Username: ";
          cin >> username;

          cout << "Enter Password: ";
          cin >> password;

          if (checkLogin(username, password))
          {
               cout << "Login Successful! Welcome, " << username << "!\n\n";

               cout << "The List Of Books Available in the Library : \n";

               ifstream file("booksInfo.txt");

               if (!file)
               {
                    cout << "Error: Could not open file!\n";
                    return;
               }

               string line;
               cout << "\n======= List of Books =======\n";

               bool isEmpty = true;
               while (getline(file, line))
               {
                    if (!line.empty())
                    {
                         cout << line << endl;
                         isEmpty = false;
                    }
               }

               file.close();
               goto student;
          }
          else
          {
               cout << "Login Failed! Incorrect Username or Password.\n\n\n";
               goto student;
          }
     }

     else if (studentid == 2)
     {
          userCredentials();
     }
     else
     {
          cout << "                         =========================\n";
          cout << "                                Wrong input!!!\n";
          cout << "                             Please enter again\n";
          cout << "                         =========================\n\n";
          goto student;
     }
}

int main()
{
     char UserInformation;
     string Username;
     string Password;

     cout << "============================================================================================" << endl;
     cout << "                            Welcome to the central library" << endl;
     cout << "============================================================================================" << endl;
     cout << endl;

     cout << "*This program allows you to choose any book available in the central library." << endl
          << "*By using this program you can get physical as well as digital copy of the book." << endl
          << "*Please readd the instructions carefully and then proceed." << endl
          << endl;

user:
     cout << "                            Who is using this program ?" << endl
          << endl;
     cout << "==============================  1.Student(Press S)    ===========================" << endl
          << "==============================  2.Librarian(Press L)  ===========================" << endl
          << endl;
     cout << "Press S or L : ";

     cin >> UserInformation;

     clearScreen();

     if (UserInformation == 'S' || UserInformation == 's')
     {
          cout << endl;
          cout << "A READER LIVES A THOUSAND LIVES BEFORE HE DIES" << endl
               << endl;

          cout << "===========================================\n";
          cout << "Are you a new student or a existing one ? \n";
          cout << "===========================================\n\n";

          students();
     }
     else if (UserInformation == 'L' || UserInformation == 'l')
     {
          Lib();
     }
     else
     {
          cout << "                              =========================\n";
          cout << "                                    Wrong input!!!\n";
          cout << "                                  Please enter again\n";
          cout << "                              =========================\n\n";
          goto user;
     }
}

// write Password
string userName()
{
     string username;
     cout << "Enter New Username: ";
     cin >> username;
     return username;
}

string passWord()
{
     string Password;
     cout << "Enter new password: ";
     cin >> Password;
     return Password;
}

void userCredentials()
{

     ofstream file("userCredentials.txt", ios::app);

     if (file.is_open())
     {
          file << endl;
          file << userName() << " ";
          file << passWord();
          file.close(); // Close the file
          cout << "Data written successfully.\n\n\n";
          students();
     }
     else
     {
          cout << "Error opening file!\n";
     }

     return;
}
