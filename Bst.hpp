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
    void insertNode(BSTNode *p,BSTNode* &t, T k);
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
    void BST<T>::insertNode(BSTNode *p,BSTNode* &t, T k){
        if(t == nullptr){
            t = new BSTNode;
            t->key = k;
            t->left = t->right = nullptr;
            t->parent = p;
        }
        else{
            if(k != t->key){
                if(k < t->key){
                    insertNode(t,t->left, k);
                }
                else{

                    insertNode(t,t->right, k);
                }
            }
        }
    }
template <typename T>
    void BST<T>:: insertNode(T k){
        insertNode(nullptr,root, k);
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
    void BST<T>:: formato (BSTNode *t){
    if (t != nullptr){
        if (t->left != nullptr) cout <<endl<< "Hijo izquierdo: " << t->left->key<< endl;
        if (t->right != nullptr) cout <<endl<< "Hijo derecho: " << t->right->key<< endl;
        if (t->parent != nullptr) cout <<endl<< "Padre: " << t->parent->key << endl;

    }
}

template <typename T>
    void BST<T>:: displayNode (BSTNode *t, int count){
        if (t != nullptr){
            count ++;
            displayNode (t->left, count);
            cout << "(" << count-1 << ")" << t->key << "";
            displayNode(t->right, count);
            /*if (t->left != nullptr) cout <<endl<< "Hijo izquierdo: " << t->left->key<< endl;
            if (t->right != nullptr) cout <<endl<< "Hijo derecho: " << t->right->key<< endl;
            if (t->parent != nullptr) cout <<endl<< "Padre: " << t->parent->key << endl;
*/
        }

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

template<typename T>
typename BST<T>:: BSTNode* BST<T>:: predecesor(BSTNode *t){
    if(t->left != nullptr){
        return maximum(t->left);
    }
    else{
        while(t = t->parent->left){
            t = t->parent;
        }
        t = t->parent;
        return t;
    }
}


template<typename T>
typename BST<T>:: BSTNode* BST<T>:: sucesor(BSTNode *t){
    if(t->right != nullptr){
        return minimum(t->right);
    }
    else{

}



#endif
// g++ main_Bst.cpp Bst .h´ -o main
//./main
