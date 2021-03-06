// Nguyen,Alison
// pa5.cpp
// 11-14-2020
// DESCRIPTION: This program will use hash tables to create a bookshelf
//      what will give you the options to browse for books, read, a book
//      view the information of a book or get a recommendation for a book
// ASSUMPTIONS:

#include <iostream>
#include <fstream>
#include <sstream>
#include "book.h"
#include "hash.h"
using namespace std;
const string FILENAME = "books-sample.csv"; //File to read in
const int BROWSE = 1;                 // constant menu choice: to browse
const int READ = 2;                   // constant menu choices: to read
const int VIEWMORE = 3;               // constant menu choices: view info
const int RECCOMEND = 4;              // constant menu choices: book rec
const int EXIT = 5;                   // constant menu choices: exit key


int main() {
    ifstream infile;                  // ifstream for read in file
    string line;                      // each line in file to read
    string title, author, rating, isbn, pages;
                                      // values read in from file
    HashTable bookshelf;              // Bookshelf hash array
    int menuChoice;                   // user's choice inside bookshelf
    long readBook;                    // ISBN keys to read desired book
    long bookInfo;                    // ISBN keys to view desired book
    long bookRec;                     // ISBN keys for recommendations

    infile.open(FILENAME);
    if (infile.fail()) {
        cout << "There is a problem in the file... Press enter... ";
        cin.get();
    } else {
        getline(infile, line);
        while (getline(infile, line)) {

            istringstream s1(line);
            getline(s1, title, ',');
            getline(s1, author, ',');
            getline(s1, rating, ',');
            getline(s1, isbn, ',');
            getline(s1, pages);


            Book addingBook = Book(title, author, stof(rating),
                            stol(isbn), stoi(pages));

            bookshelf.addToBookshelf(stol(isbn), addingBook);
        }
    }

cout << "\n\nWelcome! What would you like to do? " <<
    "\nMENU\n1. Browse for books\n2. Read a book\n3. View "
    "more info about a book\n4. Get a recommendation"
    "\n5. Exist bookshelf: "
    << "\nYour choice: ";

    cin >> menuChoice;
    while(menuChoice != EXIT) {
        switch (menuChoice) {
            case BROWSE:
                cout << "\nBrowsing for books:\n";
                bookshelf.displayAll();
                break;
            case READ:
                cout << "\nEnter the ISBN of the book you want to read: ";
                cin >> readBook;
                bookshelf.readBook(readBook);
                break;
            case VIEWMORE:
                cout << "\nEnter the ISBN of the book are interested in: ";
                cin >> bookInfo;
                bookshelf.bookInfo(bookInfo);
                break;
            case RECCOMEND:
                cout << "\nEnter the ISBN of the book you enjoyed: ";
                cin >> bookRec;
                bookshelf.recommend(bookRec);
                break;
        }
        cout << "\n\nWhat you you like to do? ";
        cin >> menuChoice;
    }

    cout << "\nYou are leaving the bookshelf... BYE! \n\n";



    return 0;
}
