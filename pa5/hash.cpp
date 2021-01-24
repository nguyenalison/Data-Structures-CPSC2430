// Nguyen,Alison
// pa5.cpp
// 11-14-2020
#include "book.h"
#include "hash.h"
#include <iostream>
using namespace std;

HashTable:: HashTable(){
    numItems = 0;
    hashTable = new BookNode*[arrSize];
    for(int i = 0; i < arrSize; i++)
        hashTable[i] = nullptr;

}

HashTable:: ~HashTable(){
    for(int i = 0; i < arrSize; i++){
        if(hashTable[i] != nullptr){
            BookNode* prev = nullptr;
            BookNode* curr = hashTable[i];
            while(curr){
                prev = curr;
                curr = curr->next;
                delete prev;
            }
        }
    }
    delete [] hashTable;
}

HashTable::BookNode::BookNode(long k, Book b) {
    key = k;
    value = b;
    next = nullptr;
}

int HashTable::hashFun(long key) {
    return key%arrSize;
}

void HashTable:: addToBookshelf(long key, Book book) {
    int hash = hashFun(key);

    BookNode *newP = new BookNode(key, book);
    numItems++;
    float loadFactor = float(numItems)/arrSize;

    if(hashTable[hash] == nullptr){
        hashTable[hash] = newP;
        cout << "\nLoad Factor: " << loadFactor;
    }else {
        BookNode* ptr = hashTable[hash];
        while (ptr->next&& ptr->key != key) {
            ptr = ptr->next;
        }if (ptr->key == key) {
            cout << "\nBook EXISTS";
        }else {
            ptr->next = newP;
        }
    }
}

void HashTable:: displayAll() {
    BookNode *ptr = nullptr;
    for (int i = 0; i < arrSize; i++) {
        if(hashTable[i] ) {
            ptr = hashTable[i];
            while(ptr) {
                cout << "\n\nTitle: " << ptr->value.getTitle()
                     << "\nISBN: " << ptr->key;
                ptr = ptr->next;
            }
        }
    }
}

void HashTable:: bookInfo(long key){
    BookNode* ptr = nullptr;
    bool exist = false;
    for(int i = 0; i < arrSize; i++){
        ptr = hashTable[i];
        while(ptr) {
            if (ptr && ptr->key == key) {
                ptr->value.printBook();
                exist = true;
            }
            ptr = ptr->next;
        }
    }
    if(!exist){
        cout << "\nThis book does not exist...";
    }
}

bool HashTable:: readBook(long key){
    bool read = false;
    int hash = hashFun(key);
    string title;
    if(hashTable[hash]){
        BookNode* prev = nullptr;
        BookNode* ptr = hashTable[hash];
        while(ptr->next != nullptr && ptr->key != key){
            prev = ptr;
            ptr= ptr->next;
        }
        if (ptr->key == key) {
            if (prev == nullptr) {
                BookNode* nextBook = ptr->next;
                title = ptr->value.getTitle();
                delete ptr;
                hashTable[hash] = nextBook;
                read = true;
            } else {
                title = ptr->value.getTitle();
                prev->next = ptr->next;
                delete ptr;
                read = true;
            }
        }
    }
    if(read)
        cout << "Reading the book " << title
             << ". Removed from bookshelf!";
    else {
        cout << "\nSorry, I dont have this book.";
    }
    return read;
}

void HashTable:: recommend(long key){
    BookNode* ptr = nullptr;
    bool exist = false;
    string writer = findAuthor(key);
    cout << "\nBook(s) by " << writer << " are: ";
    for(int i = 0; i < arrSize; i++){
        ptr = hashTable[i];
        while(ptr) {
            if (ptr->value.getAuthor() == writer) {
                cout << "\n\nTitle: " << ptr->value.getTitle()
                     << "\nISBN: " << ptr->key;
                exist = true;
            }
            ptr = ptr->next;
        }
    }
    if(!exist){
        cout << "\nThis book does not exist...";
    }
}

string HashTable::findAuthor(long key) {
    BookNode* ptr = nullptr;
    string writer;
    for(int i = 0; i < arrSize; i++){
        ptr = hashTable[i];
        while(ptr) {
            if (ptr && ptr->key == key) {
                writer = ptr->value.getAuthor();
            }
            ptr = ptr->next;
        }
    }
    return writer;
}



