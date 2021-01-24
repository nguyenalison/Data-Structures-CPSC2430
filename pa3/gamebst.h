// Nguyen, Ali
// gamebst.h
// 10-18-2020

#include <iostream>
using namespace std;
#ifndef GAMEBST_H
#define GAMEBST_H

class GameBST{
private:
    struct TreeNode{
        string key;               // Name of the game
        int maxPlayers;           // Maximum number of players
        int playTime;             // Minimum playing time
        TreeNode* left;           // Pointer to the left root of the subtree
        TreeNode* right;          // Pointer to the right root of the subtree

    };

  TreeNode* root;               // Pointer to the root


  TreeNode* copyTree(TreeNode*r);
    // Copies the values of the binary tree into another tree
    // PRE: Existing tree to copy from
    // POST: Used in the copy constructor and the copy assignment

  void insertNode(TreeNode *&r, string name, int player, int time);
    // Using pointer inserts values into the tree
    // PRE: Existing tree object to insert into
    // POST: used in the insertNode function

  void deleteNode( TreeNode *& r, string n);
    // Searches the tree for the value to remove
    // PRE: Existing tree to copy from
    // POST: used in remove()

  void printTree(TreeNode * r) const;
    // Traverses the left and right to print the tree
    // PRE: Existing tree
    // POST: Used in print()

  void printOneGame(TreeNode* r, string n);
    // Traverses the left and right to search for the game by name
    // PRE: Existing tree and existing game name
    // POST: Used int printGame()

  void printTime(TreeNode* r, int time);
    // Traverses the left and right to search games less than or equal to
    //     time passed into function
    // PRE: Existing tree and existing game time limit
    // POST: Used int printPlayable()

  void destroy(TreeNode* ptr);
    // Deletes the tree or subtree given root
    // PRE: Existing tree to copy from
    // POST: used to free memory in the copy assignment and destructor


  int findHeight(TreeNode* r);
    // Traverses the left and right to search for the existing nodes
    // PRE: Existing tree
    // POST: Returns teh height of the list as an int

  TreeNode* findMin(TreeNode* r);
     // Finds the min value in the Tree                                         
     // PRE: Existing root                                                      
     // POST: Returns the minimum value node
  
  bool searchNode(TreeNode*r, string n);
     // Searches tree for a game                                                
     // PRE: Existing tree object                                               
     // POST: Returns true or false if n exists in the list used in remove()    


public:
     // Constructors
     GameBST();
     // Default constructor
     // PRE: NONE
     // POST: Tree object made

     GameBST(const GameBST& newTree);
     // Copy constructor
     // PRE: Existing tree object to copy from
     // POST: Another tree object is created of same values as object passed in

     GameBST& operator=(const GameBST& newTree);
      // Copy constructor
      // PRE: Existing tree object to copy from
      // POST: Another tree object is created of same values as object passed in

     // Destructor
     ~GameBST();
     // Destructor
     // PRE: NONE
     // POST: Frees all memory when the program ends

     // BINARY TREE OPERATIONS
     void insert(string name, int player, int time);
     // Inserts a game, play time, and max number of players into the tree
     // PRE: Existing tree object
     // POST: New node made

     bool remove(string n);
     // Removes item from tree
     // PRE: existing Tree object and existing game name
     // POST: Returns true or false if n exists in the list

     void printGame(string name);
     // Prints the information about a game
     // PRE: Existing tree object and existing game passed into function
     // POST: NONE

     void printPlayable(int timeLeft);
     // Prints the subtree in post order
     // PRE: Existing tree object
     // POST: NONE

     void print() const;
     // Prints the entire tree in order
     // PRE: Existing tree object that is not empty
     // POST: NONE

     int getHeight();
     // Gets the height of the tree
     // PRE: existing tree object
     // POST: Returns int height of the tree

};
#endif 
