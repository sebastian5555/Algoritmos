#ifndef __MYMAP__HPP
#define __MYMAP__HPP
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename KT, typename VT>
class MyMap{
private:
    struct KeyValuePair{
        KT Key;
        VT value;
    };

    KeyValuePair *array;
    int capacity;
    int count;
    void expandCapacity();
    int findKey(KT Key);

public:
    MyMap();
    ~MyMap();

    int size();
    bool empty();
    void clear();
    void insert(KT Key, VT value);
    VT get(KT Key);
    bool containsKey(KT Key);
    void remove(KT Key);
};
#endif

template<typename KT, typename VT>
MyMap<KT,VT>:: MyMap(){
    count = 0;
    capacity = 10;
    array = new KeyValuePair[capacity];
}

template<typename KT, typename VT>
MyMap<KT,VT>:: ~MyMap(){
    delete[] array;
}

template<typename KT, typename VT>
int MyMap<KT,VT>:: findKey(KT key ){
    for(int i = 0; i<count; i++){
        if(array[i].Key == key)
        return i;
    }
    return -1;
}

template<typename KT, typename VT>
void MyMap<KT,VT>:: insert(KT Key, VT value){
    int index = findKey(Key);
    if(index == -1){
        if (count == capacity) expandCapacity();
        index = count++;
        array[index].Key = Key;
    }
    array[index].value = value;
}

template<typename KT, typename VT>
void MyMap<KT,VT>:: remove(KT Key){
    int index = findKey(Key);
    if(index == -1)
        throw runtime_error("remove: Attempting to remove value of non-existen Key\n");
    for(int i = index; i<count-1; i++){
        array[i].Key = array[i+1].Key;
        array[i].value = array[i+1].value;
    }
    count --;
}

template<typename KT, typename VT>
void MyMap<KT,VT>:: expandCapacity(){
    KeyValuePair *oldElements = array;
    capacity = 2*capacity;
    array = new KeyValuePair[capacity];
    for (int i = 0; i < count; i++){
        array[i].Key = oldElements[i].Key;
        array[i].value = oldElements[i].value;
    }

    delete oldElements;
}

template<typename KT, typename VT>
int MyMap<KT,VT>:: size(){
    return count;
}

template<typename KT, typename VT>
bool MyMap<KT,VT>:: empty(){
    return count==0;
}

template<typename KT, typename VT>
void MyMap<KT,VT>:: clear(){
    count = 0;
}

template<typename KT, typename VT>
VT MyMap<KT,VT>:: get(KT Key){
    int index = findKey(Key);
    if(index == -1){
        throw runtime_error("get: Attempting to get value of non-existen Key\n");
    }

    else{
        int c = array[index].value;
        return c;}
}

template<typename KT, typename VT>
bool MyMap<KT,VT>:: containsKey(KT Key){
    int index = findKey(Key);
    if (index == -1) return false;
    return true;
}
