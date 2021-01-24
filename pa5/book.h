// Nguyen,Alison
// pa5.cpp
// 11-14-2020

#include <string>
using namespace std;
#ifndef BOOK_H
#define BOOK_H
class Book{
private:
    string title, author;          // Each book object has a string title
    float rating;                  // and author rating, ISBN number,
    long ISBN;                     // and number of pages
    int pages;

public:
    Book();
    // Book object constructor
    // PRE: NONE
    // POST: creates a book object with default values of 0 or empty strings

    Book(string t, string a, float r, long i, int p);
    // Book object parameterized constructors
    // PRE:NONE
    // POST:creates a book object given passed in values

    void printBook();
    // prints a single book object
    // PRE: existing Book object
    // POST: none

    string getTitle();
    // Accessor method that gets the book title
    // PRE: existing Book object
    // POST: returns string book title

    long getKey();
    // Accessor method that gets the book ISBN
    // PRE: existing Book object
    // POST: returns long book ISBN

    string getAuthor();
    // Accessor method that gets the book author(s)
    // PRE: existing Book object
    // POST: returns string book authors

};
#endif
