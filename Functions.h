#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

void CLRScreen()
{
    cout << "\033[2J\033[H"; // ANSI escape codes to clear screen
}

void booksAdd();
void DisplayBooks();
void search();
void deleteBook();
int dele();
int Sear();
int read();
void clearInputBuffer(); // To clear the input buffer

void Add()
{
    int AdminInput;
    cout << "==================== Welcome Sir =====================\n\n";
    cout << "        What are you looking forward to do today ?\n";
    cout << "                   Add Books     ---(ENTER 1)\n";
    cout << "                   Delete Books  ---(ENTER 2)\n";
    cout << "                   Search Books  ---(ENTER 3) \n";
    cout << "                   Display Books ---(Enter 4) \n";
    cout << "                   Exit          ---(Enter 0) \n";
    cout << "ENTER HERE: ";
    cin >> AdminInput;

    if (AdminInput == 1)
    {
        booksAdd();
    }
    else if (AdminInput == 2)
    {
        dele();
    }
    else if (AdminInput == 3)
    {
        Sear();
    }
    else if (AdminInput == 4)
    {
        read();
    }
    else if (AdminInput == 0)
    {
        cout << "Exiting program...\n";
    }
    else
    {
        cout << "Invalid input, please try again.\n";
        Add();
    }
}

// Add Books

string bookName()
{
    string book;
    cout << "                Name of the Book : ";
    cin.ignore();
    getline(cin, book);
    return book;
}

string bookAuthor()
{
    string author;
    cout << "                Author of the Book: ";
    getline(cin, author);
    return author;
}

string description()
{
    string desc;
    cout << "                Genre of the Book: ";
    getline(cin, desc);
    return desc;
}

void booksAdd()
{
    string book = bookName();
    string author = bookAuthor();
    string desc = description();

    ofstream file("booksInfo.txt", ios::app);

    if (file.is_open())
    {
        file << endl;
        file << book << " | " << author << " | " << desc << endl;
        file.close();
        CLRScreen();
        cout << endl << endl << endl ;
        cout << "=================  Data written successfully  =====================\n\n\n";
        Add();
    }
    else
    {
        cout << "Error opening file!\n";
        Add();
    }
}

// Search Books

void search()
{
    ifstream file("booksInfo.txt");

    if (!file)
    {
        cout << "Error: Could not open file!\n";
        return;
    }

    string searchQuery;
    cout << "Enter the book name or author name to search: ";
    cin.ignore();
    getline(cin, searchQuery);

    string line;
    bool found = false;

    cout << "\n===== Search Results =====\n";
    while (getline(file, line))
    {
        if (line.find(searchQuery) != string::npos)
        {
            cout << line << endl << endl << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching book found!\n";
    }

    file.close();
    Add();
}

int Sear()
{
    char choice;
    do
    {
        cout << "\nDo you want to search for a book? (y/n): ";
        cin >> choice;
        clearInputBuffer(); // Clear input buffer to avoid issues

        if (choice == 'y' || choice == 'Y')
        {
            search();
        }

    } while (choice == 'y' || choice == 'Y');

    Add();
    return 0;
}

// Delete Books

string trim(const string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";  

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

string toLower(const string &str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void deleteBook()
{
    ifstream file("booksInfo.txt");

    if (!file)
    {
        cout << "Error: Could not open the file!\n";
        return;
    }

    string searchQuery;
    cout << "Enter the book name, author name, or genre to delete: ";
    cin.ignore();  
    getline(cin, searchQuery);
    searchQuery = toLower(trim(searchQuery));

    vector<string> lines;
    string line;
    bool found = false;

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    file.close();
    ofstream outFile("booksInfo.txt");

    if (!outFile)
    {
        cout << "Error: Could not open the file for writing!\n";
        return;
    }
    for (const string &line : lines)
    {

        string lowerLine = toLower(trim(line));

        if (lowerLine.find(searchQuery) != string::npos)
        {
            found = true;
            continue;
        }
        outFile << line << endl;
    }

    outFile.close();

    if (found)
    {
        cout << "Book successfully deleted from the file!\n";
    }
    else
    {
        cout << "No matching book found to delete.\n";
    }
}

int dele()
{
    char choice;
    do
    {
        cout << "\nDo you want to delete a book? (y/n): ";
        cin >> choice;
        clearInputBuffer(); 

        if (choice == 'y' || choice == 'Y')
        {
            deleteBook();
        }

    } while (choice == 'y' || choice == 'Y');

    Add();

    return 0;
}


// Display Books

void DisplayBooks()
{
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

    

    if (isEmpty)
    {
        cout << "No books found in the file.\n";
    }
}

int read()
{
    char choice;
    do
    {
        cout << "\nDo you want to display books? (y/n): ";
        cin >> choice;
        clearInputBuffer(); // Clear input buffer to avoid issues

        if (choice == 'y' || choice == 'Y')
        {
            DisplayBooks();
        }

    } while (choice == 'y' || choice == 'Y');

    Add();

    return 0;
}

// Helper function to clear input buffer
void clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
