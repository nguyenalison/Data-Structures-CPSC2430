// Nguyen, Ali
// pa2.cpp
// 10-12-2020

// DESCRIPTION: This program is uses a dynamic array queue, containing
// all the basic queue functions (enqueue, dequeue, isEmpty), as well as
// recursive functions, doubleEven()
// sumBigger(); print(), and a recursiveInsert.

//ASSUMPTION: A RecursiveQueue object is set to size three


#include <iostream>
#include "recursiveQueue.h"

using namespace std;

int main() {
    RecursiveQueue l;                  // Dynamic queue array object
    int numEnter;                      // Value being inserted into the arry
    int sumX;                          // Sum value of array

    cout << "\n\nWelcome. Please enter a positive integer: ";
    cin >> numEnter;
    while(numEnter < 0){
        cout << "Enter a POSITIVE integer: ";
        cin >> numEnter;
    }

    l.recInsert(numEnter);


    cout << "\nThe initial array is ";
    l.print();


    cout << "\n\nPlease enter a value for x: ";
    cin >> sumX;

    cout << "\nThe sum of the elements bigger than " << sumX << " is "
    << l.sumBigger(sumX);

    l.dequeue();
    cout << endl;
    l.print();

    cout << "\n\nThe array after double even indices: \n";
    l.doubleEven();
    l.print();


    cout << endl << endl;
    return 0;
}
