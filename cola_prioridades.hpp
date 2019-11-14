#ifndef __HEAPBINARIO_hpp
#define __HEAPBINARIO_hpp
#include <iostream>
#include <stdexcept>
using namespace std;

const int CAPACITY = 20;

template<typename  T>
class Bheap{
private:
  struct cajita{
    T datos;
    unsigned int prioridad;

  };
  cajita *array;
  int capacity ;
  int count;

  int left(int i);
  int right(int i);
  void max_heapify(int i);
  void expandcapacity();


public:
  Bheap();
  ~Bheap();

  int size();
  bool empty();
  void clear();
  void display();
  void push(T x, unsigned int k);
  T pop();
};


template<typename T>
Bheap<T>:: Bheap(){
  count = 0;
  capacity = CAPACITY;
  array = new cajita[capacity];
}

template<typename T>
Bheap<T>:: ~Bheap(){
  clear();
  delete[] array;
}

template<typename T>
int Bheap<T>:: left(int i){
  return i<<1;
}

template<typename T>
int Bheap<T>:: right(int i){
  return (i<<1) + 1;
}

template<typename T>
void Bheap<T>:: max_heapify(int i){
  int id = i+1;
  int l = left(id) - 1;
  int r = right(id) - 1;
  int largest;

  if(l < count && array[l].prioridad > array[i].prioridad)
    largest = l;
  else
    largest = i;
  if (r < count && array[r].prioridad > array[largest].prioridad)
    largest = r;

  if (largest != i){
      cajita c = array[i];
      array[i] = array[largest];
      array[largest] = c;
      max_heapify(largest);
  }
}

template<typename T>
void Bheap<T>:: expandcapacity(){
    cajita *oldElements = array;
    capacity = 2*capacity;
    array = new cajita[capacity];
    for (int i = 0; i < count; i++){
        array[i].prioridad = oldElements[i].prioridad;
        array[i].datos = oldElements[i].datos;
    }

    delete oldElements;
}

template<typename T>
int Bheap<T>:: size(){
  return count;
}

template<typename T>
bool Bheap<T>:: empty(){
  return count == 0;
}

template <typename T>
void Bheap<T>:: clear(){
  count = 0;
}

template<typename T>
void Bheap<T>:: push(T x, unsigned int k){
  cajita *cajita2 = new cajita;
  cajita2->datos = x;
  cajita2->prioridad = k;
  if (count == capacity) expandcapacity();
  //cout << "pushing " << x << " at " << count << endl;
  array[count].datos = cajita2->datos;
  array[count].prioridad = cajita2->prioridad;
  count++;

  for(int i = count/2; i>= 0; --i)
    max_heapify(i);
}

template<typename T>
T Bheap<T> :: pop(){
  if (empty())
    throw runtime_error("Pop: attempting to pop an empty queue\n");

  cajita el = array[0];
  cout << "popping " << el.datos << endl;
  array[0].prioridad = array[count-1].prioridad;
  array[0].datos = array[count-1].datos;
  count --;
  max_heapify(0);
  return el.datos;
}

template<typename T>
void Bheap<T>:: display(){
  for(int i = 0; i < count ; i++){
    cout << "(" << array[i].datos << "," << array[i].prioridad << ")" << " " << endl;
  }
  cout << endl;
}

#endif
