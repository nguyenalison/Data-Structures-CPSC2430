//BST CONATINS
bool conatins(Node* root, int x){
  if(root == nullptr)
    return false;
  else if(root->key == x)
    return true;
  else if(root->key > x)
    return contains(root->left, x);
  else
    return constaind(root->right, x);
}

//BST INSERT
int insert(Node* &root, int x){
  if(root==nullptr){
    root = new Node;
    root->key = x;
    root->left = nullptr;
    root->right = nullptr;
  }else if(root->key > x)
    insert(root->left, x);
  else
    insert(root->right, x); 
}

// BST REMOVE
void remove(Node* root, int x){
  if(root == nullptr)                  // Item not gound do nothing
    return;
  if(x < root->key)
    remove(root->left, x);
  else if( x > root->right)
    remove(root->right, x);
  else if(root->left !=nullptr && root->right!=nullptr){ // two children
    root ->key = findMin(t->right)-key;
    remove(root->right, root->key);
  }else{
    Node* old = nullptr;
    root = (root->left!=nullptr) ? root->left:root->right;
    delete old;
  }
}
//Replace data of node with smallest data of right and recursively  delete that node.

//BST FINDMIN
Node* findMin(Node*root){
  if(root ==nullptr)
    return nullptr;
  if(root->left == nullptr)
    return root;
  return findMin(root->left); 
}

Node* findMax(Node*root){
  if(root != nullptr)
    while(root->right != nullptr)
      root = root->right;
  return root;
}


//GET HEIGHT
int getHeight(Node* root){
  if( root == nullptr)
    return -1;
  else {
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);

    if(leftH >= rightH){
      return leftH +1;
    }else
      return rightH+1;
  }
}

//POST ORDER 
void postOrder(Node* root){
  postOrder(root->left);
  postOrder(root->right);
  cout << root->key << endl;
}

//INORDER                                                                       
void postOrder(Node* root){
  postOrder(root->left);
  cout << root->key << endl;
  postOrder(root->right);
}

//PREORDR       
void postOrder(Node* root){
  cout << root->key << endl;
  postOrder(root->left);
  postOrder(root->right);
}


// SUMS TREE
int sum(Node* root){
  if(root == nullptr)
    return 0;
  return (root->key + sum(root->left) + sum(root->right));
}

// DELETE ENTIRE TREE
void deleteTree(Node*root){
  if(root==nullptr)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
  root  = nullptr;
}
    
// SEARCH FOR VALUE
bool search(Node* root, int x){
  bool left, right;
  if(root == nullptr)
    return false;
  if(root->key == x)
    return true;
  left = search(root->left, x);
  if(left)
    return true;
  right = search(root->right, x);
  return right; 
}
    
//PRINTING THE INFORMATION OF A FOUND NODE
void printInfo(Node*root, int x){
  if(root){
    if(root->key == x)
      cout << root->key << endl;
    else if(r->key > n)
      print(root->left,x);
    else if(r->right < n)
      print(root->right, x);
  }
}

// PRINTING THE VALUES THAT MEET A CONDITION POST ORDER
void printTime(Node*root, int time){
  if(root){
    if(root->playTime <= time)
      cout << root->key;
    if(root->left)
      printTime(root->left, time);
    if(root->right)
      printTime(root->right, time);
  }
}

//-------------BST DATA STRUCTURE---------------------                          
// Each tree has a root node (at the top)                                       
// The root node has zero, one or two children                                  
// Each child node had zero, one or to children                                 
// Max two children                                                             
// For each node it's left child are less than the current node and the         

//-------------AVL DATA STRUCTURE----------------------                         
// SINGLE ROTATION: LL OR RR                                                    
// DOUBLE ROTATION: LR OR RL                                                    
// Difference between depth of right & left subtrees cannot > 1                 
// AVLs have the worst case O(log(n))
// IMB in left child of right sub: LR rotation
// IMB in left child of left sub: R rotation
// IMB in right child of left sub: RL roation
// IMB in right child of right sub: L rotation

//-----------------B+B- TREE-----------------------------------                   
// Root is either a left or has 2 between 2 and M children                     $
// Nonleaft node with keyNUmber of children contains keyNum-1                  $
// All nonleaf nodes except root have between ceil(m/2) and m children         $
// All leaves are at the same level                                             
// B+: ALL keys are stoed at leaves(some may also appear in internal nodes
// B+: All the data pointers are stored at leaves and leaves are linked
