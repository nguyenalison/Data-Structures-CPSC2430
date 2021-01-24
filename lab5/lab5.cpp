// Nguyen, Alison
// lab5.cpp
// 10-16-2020

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

void insert(int arr[], int currentSize, int x);
// Inserts values into a max heap
// PRE: existing array
// POST: NONE;

int deleteMax(int arr[], int currentSize);
// Deletes the max number in the heap given the capacity
// PRE: existing array
// POST: Returns deleted value in heap

void percolateDown(int arr[], int currentSize, int hole);
// Prints Rearranges heap after deletion 
// PRE: existing array
// POST: Used in deleteMax

void print(int arr[], int currentSize);
// Prints array
// PRE: existing array
// POST: NONE

int const MAXSIZE = 15;      // Maxsize for array is 15 

int main() {
    int heap[MAXSIZE];       // Heap array
    int randomNum;           // Random number chosen by computer
    int deletedNum;          // Number that is deleted from heap
    int currentSize = 0;     // Heap's capacity
    int userNum = 0;         // User input 

    srand(time(0));

    // Loop to add random numbers into heap
    for (int i = 0; i < MAXSIZE - 1; i++) {
        randomNum = (rand() % 100) + 1;
        insert(heap, currentSize, randomNum);
        currentSize++;
    }


    while(userNum < currentSize || userNum > 0) {
        cout << "\nEnter a positive number: ";
        cin >> userNum;
        if (userNum < 0) {
            cout << "Enter a positive number: ";
            cin >> userNum;
        } else if (userNum > currentSize) {
            cout << "The input is bigger than the current heap size ("
                 << currentSize << ")\n Please re-enter a number: ";
            cin >> userNum;
        }
        
        
        // Deletes all numbers greater than entered number
        for (int i = 1; i <= userNum; i++) {
            deletedNum = deleteMax(heap, currentSize);
            currentSize--;
        }

        cout << "#" << userNum << " biggest value in the heap is "
             << deletedNum;
        
        if (currentSize != 0)
            print(heap, currentSize);
        else
            cout << "\nThe heap is empty now. Goodbye!\n";
        userNum = 0;
    }
}


void insert(int arr[], int currentSize, int x){
    int hole = ++currentSize;
    arr[0] = x;
    while(x > arr[hole/2]){
        arr[hole] = arr[hole/2];
        hole/=2;
    }
    arr[hole] = arr[0];
}


void percolateDown(int arr[],int currentSize, int hole){
    int child;
    int temp = arr[hole];
    bool bubbleDown = true;
    while(bubbleDown && hole*2 <= currentSize){
        child = hole*2;
        if(child!=currentSize && arr[child+1] > arr[child])
            ++child;
        if(arr[child] > temp)
            arr[hole] = arr[child];
        else
            bubbleDown = false;
        if(bubbleDown)
            hole = child;
    }
    arr[hole] = temp;
}

int deleteMax(int arr[], int currentSize){
    int max;
    max = arr[1];
    arr[1] = arr[currentSize--];
    percolateDown(arr,currentSize, 1);
    return max;

}

void print(int arr[], int currentSize){
    cout << "\nRemaining in the heap is: \n";
    for(int i = 1; i < currentSize+1; i++)
        cout << i << ": " << arr[i] << endl;
}
