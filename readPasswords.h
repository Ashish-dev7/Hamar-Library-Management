#include<iostream>
#include <fstream>
using namespace std;

bool checkLogin(const string &inputUsername, const string &inputPassword)
{
     ifstream file("userCredentials.txt");

     if (!file)
     {
          cout << "Error: Could not open file!\n";
          return false;
     }

     string username, password;

     
     while (file >> username >> password)
     {
          if (username == inputUsername && password == inputPassword)
          {
               file.close(); 
               return true;
          }
     }

     file.close();
     return false; 
}
