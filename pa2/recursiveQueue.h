// Nguyen, Ali
// 10/06/2020
// recursiveQueue.h


#ifndef RECURSIVEQUEUE_H
#define RECURSIVEQUEUE_H
class RecursiveQueue{
private:
    int* qArray;                // Dynamic queue
    int maxSize;                // Maximum size
    int front;                  // Front of the queue
    int back;                   // Back of the queue
    int numItems;               // Number of items in the queue


    void print(int num);
    // This helper function keeps track of the indexes
    // PRE: There needs to be an existing queue
    // POST: none

    void doubleEven(int n);
    // This helper function keeps track of the indexes
    // PRE: There needs to be an existing queue
    // POST: none

    int sumBigger(int x, int count);
    // This helper function keeps track of the indexes
    // PRE: There needs to be an existing queue and positive value inputted
    // POST: Returns the sum value

public:
    RecursiveQueue();
    // Creates a Recursivequeue object
    // PRE: NONE
    // POST: NONE

    RecursiveQueue(const RecursiveQueue & newObject);
    // This is the assignment constructor for a RecursiveQueue object
    // PRE: Needs to be an existing RecursiveQueue object to be copied
    // POST: Makes a copy of a passed in RecursiveQueue

    RecursiveQueue operator=(const RecursiveQueue & newObject);
    // This is the copy constructor for a RecursiveQueue object
    // PRE: Needs to be an existing RecursiveQueue object to be copied
    // POST: Makes a copy of a passed in RecursiveQueue

    ~RecursiveQueue();
    // Destructor for RecursiveQueue
    // PRE: NONE
    // POST: All memory is released after the program ends

    void enqueue(int value);
    // Adds an int value to the back of the queue
    // PRE: Needs to be an existing RecursiveQueue
    // POST: numItems increases by one and value is added to the back

    int dequeue();
    // Takes off the last value that was added to the queue
    // PRE: Needs to be an existing RecursiveQueue that is not empty
    // POST: Returns the last item added to the queue

    bool isEmpty() const;
    // Checks if the queue is empty
    // PRE: Needs to be an existing RecursiveQueue
    // POST: Returns true if the queue is empty else false

    bool isFull() const;
    // Checks if the queue is full
    // PRE: Needs to be an existing RecursiveQueue
    // POST: Returns true if the queue is full else false

    void resize(int*& arr, int& size);
    // Resizes the maximmum size by double the one that was passed
    // PRE: Needs to be an existing RecursiveQueue
    // POST: Changes the maximum size of the array

    void recInsert(int val);
    // Takes in a positive integer and inserts each digit in the array
    // PRE: Takes in a positive value and  needs to be an existing RecursiveQueue
    // POST: Adds the values into the queue

    void doubleEven();
    // Doubles each digit at even indices
    // PRE: Needs to be an existing RecursiveQueue that is not empty
    // POST: NONE

    int sumBigger(int x);
    // Sums all the elements in the array that are bigger than x
    // PRE: Needs to be an existing RecursiveQueue
    // POST: Returns the sum

    void print();
    // Prints the queue with comma separated values
    // PRE: Needs to be an existing RecursiveQueue that is not empty
    // POST: NONE
};
#endif
