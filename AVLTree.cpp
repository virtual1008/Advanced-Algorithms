#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left , *right ;
    int height ,key;
    Node(int key){
       this->key = key;
       left = nullptr;
       right = nullptr;
       height = 1;
    }
};
int height(Node* node){
    if(node==nullptr) return 0;
    return node->height;
}
int getBalance(Node* node){
    if(node==nullptr) return 0;
    return height(node->left) - height(node->right);
}

Node* minValueNode(Node* node){
    Node* curr = node;
    while(curr->left!=nullptr){
        curr = curr->left;
    }
    return curr;
}

// A utility function to right rotate 
// subtree rooted with y
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left),
                height(y->right));
    x->height = 1 + (height(x->left),
                height(x->right));

    // Return new root
    return x;
}
// A utility function to left rotate 
// subtree rooted with x
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left),
                height(x->right));
    y->height = 1 + max(height(y->left),
                height(y->right));

    // Return new root
    return y;
}

Node* insert(Node* node, int key) {
    if(node==nullptr) return new Node(key);
    if(key<node->key){
        node->left = insert(node->left,key);
    }else if(key>node->key){
        node->right = insert(node->right,key);
    }else  return node;

    node->height = 1 + max(height(node->left),height(node->right));
    
    int balance = getBalance(node);

    //Case 1: Left Left
    if(balance>1 && node->left->key>key){
        return rightRotate(node);
    }
    //Case 2: Left Right
    if(balance>1 && node->left->key<key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //Case 3: Right Right
    if(balance<-1 && node->right->key<key){
        return leftRotate(node);
    }
    //Case 4: Right Left
    if(balance<-1 && node->right->key>key){
         node->right = rightRotate(node->right);
         return leftRotate(node);
    }
    return node;
}

Node* DeleteNode(Node* node , int key){
      if(node==nullptr) return node;
      if(key<node->key){
         node->left = DeleteNode(node->left,key);
      }else if(key>node->key){
        node->right = DeleteNode(node->right,key);
      }else{
          if(node->left==nullptr || node->right==nullptr){
             Node* temp = node->left?node->left:node->right;
             if(temp==nullptr){
                temp = node;
                node = nullptr;
             }else{
                *node = *temp;
                free(temp);
             }
          }else{
             Node* temp = minValueNode(node);
             node->key = temp->key;
             node->right = DeleteNode(node->right,temp->key);
          }
      }
      if(node==nullptr) return node;
      node->height = 1+max(height(node->left),height(node->right));
      
      int balance = getBalance(node);

      // case 1 : left left
      if(balance>1 && getBalance(node->left)>=0)
          return rightRotate(node);
      // case 2 : left right
      if(balance>1 && getBalance(node->left)<0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
      }
      // case 3 : right right
      if(balance<-1 && getBalance(node->right)<=0)
         return leftRotate(node);
      // case 4 : right left
      if(balance<-1 && getBalance(node->right)>0){
          node->right = rightRotate(node->right);
          return leftRotate(node);
      }
      return node;
}

void LevelOrderTravesal(Node* root){
    if(root==nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            auto it = q.front();
            q.pop();
            cout<<it->key<<" ";
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
        }
        cout<<"\n";
    }
}
int main(){
    Node *root = nullptr;

    // Constructing tree given in the 
    // above figure
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 0);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 7);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    LevelOrderTravesal(root);

    root = DeleteNode(root, 1);

    cout << "\nPreorder traversal after"
            " deletion of 10 \n";
    LevelOrderTravesal(root);

    return 0;
}