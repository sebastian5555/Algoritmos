#ifndef __MYLISTQUEUE_HPP
#define __MYLISTQUEUE_HPP

#include <iostream>
#include <stdexcept>
using namespace std;


namespace qlist {
  template <typename T>
  class MyQueue {
  private:
    struct Cell {
      T el;
      Cell *next;
    };

    Cell *back; //pointer to end of queue
    Cell *front; //pointer to begining of queue
    int count; //No. of elements

  public:
    MyQueue() : back(nullptr), front(nullptr), count(0) {};
    ~MyQueue();

    bool empty();
    int size();
    T get_back();
    T get_front();
    void push(T c); //adds element at the back
    T pop(); //removes element from the front
    void clear(); //removes all elements
  };
}


template <typename T>
qlist::MyQueue<T>::~MyQueue() {
  clear();
}

template <typename T>
bool qlist::MyQueue<T>::empty() {
  return front == nullptr;
}

template <typename T>
int qlist::MyQueue<T>::size() {
  return count;
}

template <typename T>
T qlist::MyQueue<T>::get_back() {
  if(empty())
    throw runtime_error("get_back: Attempting to get value from empty queue\n");
  return back->el;
}

template <typename T>
T qlist::MyQueue<T>::get_front() {
  if(empty())
    throw runtime_error("get_front: Attempting to get value from empty queue\n");
  return front->el;
}

template <typename T>
void qlist::MyQueue<T>::push(T c) {
    Cell *nueva = new Cell;
    nueva->el = c;
    if(empty()){
        nueva->next=nullptr;
        cout << nueva->el;
    }
    else{
        back->next = nueva;
        nueva->next = nullptr;
        back = nueva;
        count ++;
        cout << nueva->el;
    }
}

template <typename T>
T qlist::MyQueue<T>::pop() {
    if(empty())
        throw runtime_error("pop: Attempting to pop an empty queue\n");
    Cell *nueva = front;
    front = front->next;
    T nuevo = nueva->el;
    return nuevo;
    delete[] nueva;
    count --;
}

template <typename T>
void qlist::MyQueue<T>::clear() {
    while(!empty())
      pop();
    count = 0;
}


#endif
