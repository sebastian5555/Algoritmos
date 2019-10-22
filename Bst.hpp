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
        BSTNode *parent;

    };
    BSTNode *root;
    void insertNode(BSTNode* &t, T k);
    void destroyRecursive(BSTNode *t);
    void displayNode (BSTNode *t, int count);
    BSTNode* findNode(BSTNode *t, T k);
    BSTNode* minimum(BSTNode *t);
    BSTNode* maximum(BSTNode *t);

public:
  BST() {root = nullptr;}
  ~BST();
  void insertNode(T k);
  void displayNode();
  BSTNode* findNode(T k);
  BSTNode* minimum();
  BSTNode* maximum();


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
                    t->parent = t->key;
                    insertNode(t->left, k);
                }
                else{
                    t->parent = t->key;
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
            //cout << "Destruyendo " << t->key << "\n";
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
        cout << "Hijo izquierdo: " << t->left<< endl;
        cout << "Hijo derecho: " << t->right<< endl;
        cout << "Padre: " << t->parent<< endl;
    }

template <typename T>
    void BST<T>:: displayNode(){
        displayNode(root, 0);
    }

template <typename T>
typename BST<T>::BSTNode* BST<T>:: findNode(BSTNode *t, T k){
        if (t == nullptr) return nullptr;
        if (k == t->Key) return t;
        if (k < t->key){
            return findNode(t->left,k);
        }
        else{
            return findNode(t->right,k);
        }
    }

template <typename T>
typename BST<T>::BSTNode* BST<T>:: findNode(T k){
    return finNode(root, k);
        }

template <typename T>
typename BST<T>:: BSTNode* BST<T>:: minimum(BSTNode *t){
    while(t->left != nullptr)
        t = t->left;
    return t;
}

template<typename T>
typename BST<T>:: BSTNode* BST<T>:: minimum(){
    return minimum(root);
}

template <typename T>
typename BST<T>:: BSTNode* BST<T>:: maximum(BSTNode *t){
        while(t->right != nullptr)
            t = t->right;
        return t;
    }

template<typename T>
typename BST<T>:: BSTNode* BST<T>:: maximum(){
    return maximum(root);
}



#endif
// g++ main_Bst.cpp Bst .h´ -o main
//./main
