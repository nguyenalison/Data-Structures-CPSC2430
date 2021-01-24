// Nguyen, Ali
// lab4.cpp
// 10.08.2020
// This programs creates a binary search tree based on user input

#include <iostream>

using namespace std;

typedef int treeElement;

struct BNode{
    treeElement value;
    BNode* left;
    BNode* right;
};

bool insert(BNode* &n, treeElement k);
    // Inserts node into binary tree
    // PRE: Existing root node
    // POST: Returns true if the value already exists in tree, else false

void insert(BNode*& n, BNode*& newNode);
    // Helper function for inserting by pointers
    // PRE: Existing root node
    // POST: none

bool searchVal(BNode* &n, treeElement k);
    // Searches for specific value in tree
    // PRE: Existing root node
    // POST: Returns true or false if the value is found (used in insert())

treeElement sum(BNode*& n);
    // Sums all the values in the tree
    // PRE: Existing root node
    // POST: Returns sum value of typedef

void print(BNode*n, int k);
    // Prints the values of the subtree smaller than a given value
        // in preorder traversal
    // PRE: Existing root node
    // POST: none

void deleteTree(BNode* &root);
    // Deletes all the nodes in the tree i
    // PRE: Existing root node and tree
    // POST: none


int main() {
    int numEl;                         // Number of keys to be added to tree
    int numKey;                        // Number at which tree is printed
    treeElement val;                   // Value inserted by user
    bool duplicate;                    // Bool for if there is a duplicate
    BNode* root = nullptr;             // Root node for tree

    cout << "How many keys do you want to add to the BST? ";
    cin >> numEl;

    while(numEl < 0){
        cout << "Enter a positive number of keys you want to add: ";
        cin >> numEl;
    }

    for (int i = 0; i < numEl; i++) {
        cout << "Enter the key you want to insert:";
        cin >> val;
        while (val < 0) {
          cout << "Enter a positive integer!" 
               << "Enter the key you want to insert: ";
            cin >> val;
        }
        duplicate = insert(root,val);
        while(duplicate){
          cout << "This value is already in the tree. "
               << "Please enter another number: ";
            cin >> val;
            duplicate = false;
        }
        insert(root, val);
    }


    cout << "\nEnter a key: ";
    cin >> numKey;

    cout << "Values smaller than "<< numKey << " are:\n";
    print(root, numKey);

    cout << "\nThe sum of the tree is: " << sum(root);

    cout << "\nThe tree is empty now. Bye!\n";
    deleteTree(root);

    return 0;
}


void insert(BNode*& n, BNode*& newNode){
    if(n == nullptr)
        n = newNode;
    else if( newNode->value < n->value)
        insert(n->left, newNode);
    else
        insert(n->right, newNode);
}

bool insert(BNode* &n, treeElement k){
    bool stat = false;
        BNode *ptr = n;
        ptr = new BNode;
        if(searchVal(n,k)){
            stat = true;
        }else {
            ptr->value = k;
            ptr->left = ptr->right = nullptr;
            insert(n, ptr);
        }
    return stat;
}

bool searchVal(BNode* &n, treeElement k){
    bool statL, statR;
    if(n == nullptr)
        return false;
    if(n->value == k)
        return true;
    statL = searchVal(n->left, k);
    if(statL)
        return true;
    statR = searchVal(n->right, k);
    return statR;
}

treeElement sum(BNode* &n){
    if(n== nullptr)
        return 0;
    else{
        return n->value + sum(n->left)+ sum(n->right);
    }

}

void print(BNode*n, int k){
    if(n && k > n->value){
        cout << n->value << endl;
        print(n->left, k);
        print(n->right,k);
    }
}

void deleteTree(BNode* &root){
    if(root== nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}
