// Ali Nguyen
// lab3.cpp
// 09-25-2020

#include <iostream>
#include <istream>

using namespace std;
typedef int nodeType;

struct Node                    //Struct Node for linked list
{
    nodeType val;
    Node * next;
};


void add(nodeType num);
    // Adds node objects holding values in a linked list
    // Pre: To add a num must be passed into the parameters
    // Post: A value is added to the back of the linked list


nodeType reverse(Node* ptr,int numElements);
    // Reverses the linked list from the head to the number of elements passed
    // Pre: There has to be an existing linked list
    // Post: Example list of 1 2 3 4 exists after this call 4 3 2 1 is printed


nodeType sumList(Node* ptr,int numEl);
    // Adds all the values in the linked list
    // Pre: There has to be an existing linked list
    // Post: returns the sum of the values in the linked list

void deleteList();
    // Deletes all of the linked list to deallocate memory
    // Pre: There has to be an existing linked list
    // Post: Frees memory

Node* head;                 // Node object that is the head

int main() {
    int numElements;        // Number of elements user wants to add
    int numReverse;         // Element they want to reverse at
    nodeType numVal;        // Values user chooses to enter
    nodeType total;         // Sum of reversed list
    head = nullptr;         // head of list is first assigned to nullptr

    cout << endl <<"Welcome. "
         << "How many elements do you want to add to the list? ";
    cin >> numElements;

    
    for(int i = 0; i < numElements; i++){
      cout << "Please enter a number: ";
        cin >> numVal;
        add(numVal);
    }

    cout << "How many values do you want to reverse print? ";
    cin >> numReverse;
    total = reverse(head,numReverse);

    cout << endl << "The sum of these numbers is: " << total << endl << endl;

    deleteList();
    
    return 0;
}


void add(nodeType num){
    Node* ptr;
    Node* newN;

    newN = new Node;
    newN->val = num;
    newN->next = nullptr;
     if(!head){
         head = newN;
     }else{
         ptr = head;
         while(ptr->next){
             ptr = ptr->next;
         }
         ptr->next = newN;
     }
}


nodeType reverse(Node* ptr,int numElements){
    nodeType sum;
    if(!ptr || numElements <= 0){
        return 0;
    }else {
        numElements--;
        reverse(ptr->next, numElements);
        cout << ptr->val << " ";
    }
    sum = sumList(ptr, numElements);
    return sum;
}



nodeType sumList(Node*ptr, int numEl){
    ptr = head;
    nodeType sum = 0;

    while(ptr && numEl >= 0){
        sum += ptr->val;
        ptr = ptr->next;
        numEl--;
    }

    return sum;
    delete head;
}


void deleteList(){
    Node* ptr = head;
    Node* temp;

    while(ptr!= nullptr){
        temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
    head = nullptr;

}
