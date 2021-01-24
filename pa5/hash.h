// Nguyen,Alison
// pa5.cpp
// 11-14-2020

using namespace std;
#include "book.h"
#ifndef HASH_H
#define HASH_H

const int arrSize = 7;
class HashTable{
private:
    struct BookNode{          // BookNode will be a pointer for linked list
        long key;              // Holds book ISBN
        Book value;           // BookNode will have a Book object
        BookNode* next;       // pointer to next BookNode
        BookNode(long k, Book b);  // BookNode constructor
    };

    BookNode** hashTable;      // Hashtable array of BookNodes
    int numItems;              // number of books in array
    int hashFun(long key);
    // Given a long key a hash value will be calculated
    // PRE: Existing hashtable
    // POST: returns hash value

    string findAuthor(long key);
    // Given a long key finds the author of the book
    // PRE: Existing hashtable
    // POST: returns a string of the author(s) name

public:
    HashTable();
    // Hashtable constructor
    // PRE: Existing hashtable
    // POST: sets all values in array to nullptr

    ~HashTable();
    // Hashtable destructor
    // PRE: Existing hashtable
    // POST: frees hashtable memory

    void addToBookshelf(long key, Book book);
    // Adds Book objects into hashtable
    // PRE: Existing hashtable
    // POST: numItems increases by one

    bool readBook(long key);
    // User "reads" book and it will be removed from bookshelf
    // PRE: Existing hashtable
    // POST: returns false if book is not in shelf

    void bookInfo(long key);
    // Given a ISBN key it will print that book's information
    // PRE: Existing hashtable
    // POST: NONE

    void displayAll();
    // Displays all books in the bookshelf printing Title and ISBN
    // PRE: Existing hashtable
    // POST: NONE

    void recommend(long key);
    // Given a ISBN key prints other books written by the same author
    // PRE: Existing hashtable
    // POST: NONE
};
#endif
