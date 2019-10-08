#ifndef __Bst__hpp
#define __Bst__hpp
#include <iostream>
using namespace std;


template <typename T>

class BST {
private:
    struct BSTNode {
        T key;
        BSTNode *left;
        BSTNode *right;
    };
    BSTNode *root;
    void insertNode(BSTNode* &t, T k);
    void destroyRecursive(BSTNode *t);
    void displayNode (BSTNode *t, int count);
public:
  BST() {root = nullptr;}
  ~BST();
  void insertNode(T k);
  void displayNode();

};

template <typename T>
    void BST<T>::insertNode(BSTNode* &t, T k){
        if(t == nullptr){
            t = new BSTNode;
            t->key = k;
            t->left = t->right = nullptr;
        }
        else{
            if(k != t->key){
                if(k < t->key){
                    insertNode(t->left, k);
                }
                else{
                    insertNode(t->right, k);
                }
            }
        }
    }
template <typename T>
    void BST<T>:: insertNode(T k){
        insertNode(root, k);
    }

template <typename T>
    void BST<T>:: destroyRecursive(BSTNode *t){
        if (t != nullptr){
            destroyRecursive(t->left);
            destroyRecursive(t->right);
            cout << "Destruyendo " << t->key << "\n";
            delete t;
        }
    }
template <typename T>
    BST<T>:: ~BST(){
        destroyRecursive(root);
        }

template <typename T>
    void BST<T>:: displayNode (BSTNode *t, int count){
        if (t != nullptr){
            count ++;
            displayNode (t->left, count);
            cout << "(" << count-1 << ")" << t->key << "";
            displayNode(t->right, count);
        }
    }

template <typename T>
    void BST<T>:: displayNode(){
        displayNode(root, 0);
    }

#endif
// g++ main_Bst.cpp Bst .h´ -o main
//./main
