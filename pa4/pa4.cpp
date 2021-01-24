// Nguyen, Alison
// pa4.cpp
// 10-26-2020
// DESCRIPTION: This program uses a dynamic array to create a max heap of
//         strings. The strings will be inserted by a max heap insert
//         with the longest words as priority.
// ASSUMPTION: A heap array object is set to size three

#include <iostream>
#include <string>
#include "heap.h"

using namespace std;

int main() {
    WordHeap x;             // Word heap array
    int values;             // Size of array determined by
    string word;            // strings inserted by user
    string parent;          // parent chosen by user to print children

    cout << "\n\nHow many values do you want to add to the heap? ";
    cin >> values;
    while (values <= 0){
      cout << "Value must be greater than 0! Enter another value: ";
      cin >> values;
    }
    
    for(int i = 0; i < values; i++){
        cout << "Enter a word you want to add: ";
        cin >> word;
        x.insert(word);
    }

    WordHeap cc(x);          // Wordheap made by copy constructor
    WordHeap ca;             // Wordheap made by copy assignment
    ca = x;

    cout << endl << "Which values do you want to print the children of? ";
    cin >> parent;
    x.printChildren(parent);

    cout << "\n\nEMPTYING HEAP1:\n";
    x.makeEmpty();

    cout << "\nMAKING HEAP2 WITH COPY CONSTRUCTOR COPYING HEAP1:\n";
    cout << "\nDELETING MAX FROM HEAP2: ";
    cout << cc.deleteMax();
    cout << "\nDELETING MAX FROM HEAP2: ";
    cout << cc.deleteMax();
    cout << "\nEMPTYING HEAP2:\n";
    cc.makeEmpty();

    cout << "\nMAKING HEAP3 WITH COPY ASSIGNMENT COPYING HEAP2:\n";
    cout << "\nINSERTING six666 INTO HEAP3: ";
    ca.insert("six666");
    cout << "\nINSERTING eight888 INTO HEAP3: ";
    ca.insert("eight888");
    cout << "\nEMPTYING HEAP3:\n";
    ca.makeEmpty();


    return 0;
}
