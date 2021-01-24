// Nguyen, Alison
// heap.h
// 10-23-2020

#include <string>
#include <iostream>
#include "heap.h"

using namespace std;

WordHeap:: WordHeap(){
    maxSize = 3;
    numItems = 0;
    heap = new Item[maxSize];
}

WordHeap:: WordHeap(const WordHeap &object){
    heap = new Item[object.maxSize];
    numItems = object.numItems;

    for(int i = 0; i < object.maxSize; i++)
        heap[i] =  object.heap[i];
}

WordHeap WordHeap:: operator=(const WordHeap& object) {
    delete[] heap;

    heap = new Item[object.maxSize];
    numItems = object.numItems;

    for (int i = 0; i < object.maxSize; i++) {
        heap[i] = object.heap[i];
    }

    return *this;
}

WordHeap:: ~WordHeap(){
    delete [] heap;
}

void WordHeap::insert(string x) {
    if(numItems==maxSize-1){
        resize();
    }
    int hole = ++numItems;
    Item newI;
    newI.word = x;
    newI.key = x.length();
    heap[0] = newI;
    while (newI.key > heap[hole/2].key) {
            heap[hole] = heap[hole/2];
            hole /= 2;
    }
    heap[hole] = heap[0];

}

void WordHeap::resize() {
  Item* temp = new Item[maxSize*2];

  for(int i = 0 ; i < maxSize; i++)
    temp[i] = heap[i];

  maxSize*=2;
  delete [] heap;
  heap = temp; 
  cout << "Array is full. Resizing to " << maxSize << " elements." << endl;
}

string WordHeap:: deleteMax(){
    if(numItems == 0){
      cout << "Heap is empty!\n";
      return "";
    }else {
        Item max;
        max.word = heap[1].word;
        heap[1] = heap[numItems--];
        percolate(1);
        return max.word;
    }
}

void WordHeap::percolate(int hole){
    int child;
    Item temp = heap[hole];
    bool bubbleUp = true;

    while(bubbleUp && hole*2 <= numItems) {
        child = (hole * 2);
        if (child != numItems && heap[child + 1].key > heap[child].key)
            ++child;
        if (heap[child].key > temp.key)
            heap[hole] = heap[child];
        else
            bubbleUp = false;
        if (bubbleUp == true) {
            hole = child;
        }
    }
    heap[hole] = temp;
}

void WordHeap:: makeEmpty(){
    string deleting;
    cout << "Emptying the heap:\n";
    while(numItems!= 0){
        deleting = deleteMax();
        cout << deleting << endl;
    }
}

void WordHeap:: printChildren(string x){
    Item ptr;
    int left, right;
    bool stat = false;
    for(int i =0; i < maxSize; i++){
        left = 2*i;
        right = (2*i)+1;
        if(heap[i].word==x){
            stat = true;
            if(heap[left].word == "")
                heap[left].word = "nullptr";
            if(heap[right].word == "")
                heap[right].word = "nullptr";
            cout << "Left Child: " << heap[left].word
            << "\nRight Child: " << heap[right].word;
        }
    }
    if(!stat)
        cout << x << " is not in the heap.\n";
}

