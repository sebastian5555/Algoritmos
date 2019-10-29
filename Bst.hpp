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
//    BSTNode* formato(BSTNode *t);
    BSTNode* predecesor(BSTNode *t);
    BSTNode* sucesor(BSTNode *t);
    BSTNode* remove(BSTNode *t);

public:
  BST() {root = nullptr;}
  ~BST();
  void insertNode(T k);
  void displayNode();
  BSTNode* findNode(T k);
  BSTNode* minimum();
  BSTNode* maximum();
 // BSTNode* formato();
 BSTNode* predecesor();
 BSTNode* sucesor();
  BSTNode* remove(T t);


};

template <typename T>
    void BST<T>::insertNode(BSTNode *p,BSTNode* &t, T k){
        if(t == nullptr){
            t = new BSTNode;
            t->key = k;
            t->left = t->right = nullptr;
            t->parent = p;first.insertNode(5);
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
/*
template <typename T>
    typename BST<T>:: BSTNode* BST<T>:: formato (BSTNode *t){
    if (t != nullptr){
        if (t->left != nullptr) cout <<endl<< "Hijo izquierdo: " << endl;
            return t->left->key;first.insertNode(5);
        if (t->right != nullptr) cout <<endl<< "Hijo derecho: " << endl;
            return t->right->key;
        if (t->parent != nullptr) cout <<endl<< "Padre: " << endl;
            return t->parent->key;

    }
}
*/
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
            if (k == t->key) return t;
            if (k < t->key){
                return findNode(t->left,k);
            }
            else{
                return findNode(t->right,k);
            }
        }

template <typename T>
    typename BST<T>::BSTNode* BST<T>:: findNode(T k){
        return findNode(root, k);
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
            while(t = t->parent->right){
                t = t->parent;
            }
            t = t->parent;
            return t;
        }
    }

template<typename T>
    typename BST<T>:: BSTNode* BST<T>:: remove (BSTNode *t){
        BSTNode *p = t->parent;
        if(t->left == nullptr && t->right == nullptr){
            if(t == p->left){
                p->left = nullptr;
                }
            if(t == p->right){
                p->right = nullptr;
                }

        }
        else if(t->left != nullptr && t->right == nullptr){
            if(t == p->left){
                p->left = t->left;
                }
            if(t == p->right){
                p->right = t->left;
                }

        }
        else if(t->right != nullptr && t->right == nullptr){
            if(t == p->left){
                p->left = t->right;
                }
            if(t == p->right){
                p->right = t->right;
                }
        }
        return p;
        delete[] t;
    }

template<typename T>
    typename BST<T>:: BSTNode* BST<T>:: remove(T t){
        BSTNode *kt = findNode(t);
        return remove(kt);
    }


#endif
// g++ main_Bst.cpp Bst.hpp -o main
//./main
