#ifndef __HASH_HPP
#define __HASH_HPP
#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <limits>
using namespace std;

const int TABLE_SIZE = 1013;

template<typename VT>
class HashMap{
private:
    struct KeyValueNode {
        string key;
        VT value;
        KeyValueNode *next;
    };
    KeyValueNode **table;
    int tableSize;
    int count;

    VT notfound;

    KeyValueNode * search_bucket(int index, string key);

    //Hash function
    unsigned int hash(string key){
        unsigned int hashVal = 0;
        for (char ch : key)
            hashVal += ch;
        return hashVal % tableSize;
    }
public:
    HashMap(VT def);
    ~HashMap();

    int size();
    bool empty();
    void clear();

    void display();

    VT get(string key);
    bool search(string key);
    void insert(string key, VT value);
    void remove(string key);

    void distribution(const string &filename);
};

template<typename VT>
HashMap<VT>:: HashMap(VT def){
    notfound = def;
    count = 0;
    tableSize = TABLE_SIZE;
    table = new KeyValueNode*[TABLE_SIZE];
    for( int i = 0; i < tableSize; i++){
        table[i] = nullptr;
    }
}
template<typename VT>
HashMap<VT>:: ~HashMap(){

}

template<typename VT>
int HashMap<VT>:: size(){
    return count;
}

template <typename VT>
bool HashMap<VT>:: empty(){
    if (count == 0) return true;
    else return false;
}

template<typename VT>
void HashMap<VT>:: clear(){

}

template<typename VT>
void HashMap<VT>:: display(){
    for ( int i = 0; i < count; i++){
        cout << i  << " ";
        KeyValueNode *indice = table[i];
        while (indice->next != nullptr){
            cout << indice->key << " ";
            indice = indice->next;
        }
        cout << endl;
    }
}

template<typename VT>
VT HashMap<VT>:: get(string key){
    KeyValueNode *indice = table[hash(key)];
    while (indice->next != nullptr){
        if (indice->key == key){
            return indice->value;
        }
        else
            return notfound;
    }
}

template<typename VT>
void HashMap<VT>:: insert(string key, VT value){
    KeyValueNode *indice = table[hash(key)];
    KeyValueNode *caja = new KeyValueNode;
    indice = caja;
    caja->key = key;
    caja->value = value;

    if (indice == nullptr){
        caja->next = nullptr;
    }
    else{
        KeyValueNode *temporal = indice;
        caja->next = temporal;
    }
    cout << indice;
}
#endif
