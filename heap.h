// Nguyen, Alison
// heap.h
// 10-31-2020

#ifndef HEAP_H
#define HEAP_H
using namespace std;

class WordHeap{
private:
    struct Item{                 // Item object stored in heap array
        string word;             // Word to insert into array
        int key;                 // Priority key (length of string)
    };
    Item* heap;                  // Dynamic heap array pointer
    int numItems;                // Number of items in heap
    int maxSize;                 // max size of heap

    void percolate(int hole);
    // This swaps the deleting value with the last item in the array
    // PRE: Existing heap array that is not empty
    // POST: NONE

    void resize(Item*& arr, int&size);
    // Doubles the array size
    // PRE: existing heap array that is full
    // POST: Doubles the maxSize



public:
    WordHeap();
    // Creates a WordHeap object
    // PRE: NONE
    // POST: NONE

    WordHeap(const WordHeap &object);
    // This is the copy constructor for a WordHeap object
    // PRE: Needs to be an existing heap array  object to be copied
    // POST: Makes a copy of a passed in WordHeap

    WordHeap operator=(const WordHeap& newObject);
    // This is the copy assignment for a WordHeap object
    // PRE: Needs to be an existing heap array  object to be copied
    // POST: Makes a copy of a passed in WordHeap

    ~WordHeap();
    // Destructor for WordHeap
    // PRE: NONE
    // POST: All memory is released after the program ends

    void insert(string x);
    // Adds Item objects into the heap
    // PRE: Existing heap array
    // POST: numItems in the array increases

    string deleteMax();
    // Deletes the max value or value at array[1]
    // PRE: Non Empty heap array
    // POST: returns string of deleted value

    void printChildren(string x);
    // Prints the children given a node
    // PRE: Heap array object and value passed in must exist
    // POST: NONE

    void makeEmpty();
    // Prints out all the deleted values until heap is empty
    // PRE: NONE
    // POST: NONE


};
#endif
