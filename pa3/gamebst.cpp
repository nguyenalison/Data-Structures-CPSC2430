// Nguyen, Ali
// gamebst.cpp
// 10-18-2020

#include "gamebst.h"
#include <iostream>

using namespace std;

GameBST ::GameBST() {
    root = nullptr;
}


GameBST ::GameBST(const GameBST& newTree){
    root = copyTree(newTree.root);
}


GameBST& GameBST:: operator=(const GameBST& newTree){
    destroy(root);
    root = copyTree(newTree.root);
    return *this;
}


GameBST :: TreeNode* GameBST:: copyTree(TreeNode*r){
    if(r== nullptr)
        return nullptr;
    else{
        return new TreeNode{r->key, r->maxPlayers, r->playTime,
                            copyTree(r->left), copyTree(r->right)};
    }
}


GameBST:: ~GameBST(){
    destroy(root);
}


void GameBST:: insertNode(TreeNode *& r, string name, int player, int time){
    if(r == nullptr){
        r = new TreeNode;
        r->key = name;
        r->maxPlayers = player;
        r->playTime = time;
        r->left = nullptr;
        r->right = nullptr;
    }else if( r->key > name)
        insertNode(r->left, name, player, time);
    else
        insertNode(r->right, name, player, time);
}


void GameBST:: insert(string name, int player, int time){
    insertNode(root, name, player, time);
}


void GameBST:: destroy(TreeNode* ptr){
    if(ptr) {
        if (ptr->left)
            destroy(ptr->left);
        if (ptr->right)
            destroy(ptr->right);
        delete ptr;
    }
}


GameBST :: TreeNode* GameBST:: findMin(TreeNode* r){
    if(r == nullptr)
        return nullptr;
    else if(r->left == nullptr)
        return r;
    return findMin(r->left);
}


void GameBST:: deleteNode(TreeNode*&r, string n) {
    if( r == nullptr)
        return;
    if( n < r->key)
        deleteNode(r->left,n);
    else if(n > r->key)
        deleteNode(r->right, n);
    else if(r->left!= nullptr && r->right!= nullptr){
        r->key = findMin(r->right)->key;
        deleteNode(r->right, r->key);
    }else{
        TreeNode* old = r;
        r = (r->left!= nullptr) ? r->left: r->right;
        delete old;
    }
}


bool GameBST:: remove(string n) {
    if (searchNode(root,n)) {
        deleteNode(root, n);
        return true;
    }else
        return false;
}


void GameBST:: print() const{
    printTree(root);
}


void GameBST:: printTree(TreeNode * r) const{
    if(r){
        printTree(r->left);
        cout <<  r->key << endl;
        printTree(r->right);
     }
}

void GameBST:: printOneGame(TreeNode* r, string n){
    if(r) {
        if (r->key == n)
            cout << "Game: " << r->key
                 << "\nMaximum #of players: " << r->maxPlayers
                 << "\nMinimum playtime: " << r->playTime << " mins\n";
        else if (r->key > n) {
            printOneGame(r->left,n);
        }else {
            printOneGame(r->right,n);
        }
    }
}

void GameBST:: printGame(string name){
    if (searchNode(root,name)) {
        printOneGame(root, name);
    }else
        cout << "This game does not exist... \n";
}

void GameBST:: printTime(TreeNode* r, int time){
  if(r){
    if(r->playTime <= time)
      cout << r->key << endl;
    if(r->left){
      printTime(r->left, time);
    }
    if(r->right){
      printTime(r->right, time);
    }
  }
}

void GameBST::printPlayable(int timeLeft) {
    printTime(root, timeLeft);
}


bool GameBST:: searchNode(TreeNode*r, string n){
    bool statL, statR;
    if(r == nullptr)
        return false;
    if(r->key == n)
        return true;
    statL = searchNode(r->left, n);
    if(statL)
        return true;
    statR = searchNode(r->right, n);
    return statR;
}


int GameBST:: findHeight(TreeNode *r) {

    if (!r){
        return -1;
    }else {
        int lHeight = findHeight(r->left);
        int rHeight = findHeight(r->right);

        if (lHeight >= rHeight) {
            return lHeight + 1;
        } else {
            return rHeight + 1;
        }
    }
}

int GameBST:: getHeight(){
    return findHeight(root);
}




