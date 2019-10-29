#ifndef __DLIST__HPP
#define __DLIST__HPP
#include <iostream>
using namespace std;


template < typename dataType >
class List {
private :
  struct Node_Cell {
    dataType datos;
    Node_Cell *anterior;
    Node_Cell *siguiente;

  };

public :
  List () ; // create empty list
  List ( const List & other ) ; // new list from other list
  ~ List () ; // destroy list & contents

  List & operator =( const List & other ) ;

  int size () const ; // return number of elements
  bool empty () const ; // check if container is empty
  void clear () ; // clear contents of list

  dataType & back () ; // access last element
  dataType & front () ; // access first element

 void push_back ( dataType & rhs ) ; // insert at end
 void push_front ( dataType & rhs ) ; // insert at beg
 void pop_back () ; // remove last item
 void pop_front () ; // remove first item

private :
 int count ; // number of elements
 /* insert other fields for List */
 Node_Cell *first;
 Node_Cell *last;
};


template<typename dataType>
List<dataType>:: List(){
  count = 0;
  first->anterior = nullptr;
  last->siguiente = nullptr;
}

List:: List(const List & other){
  anterior = other->anterior;
  siguiente = other->siguiente;
  datos = other->datos;
}

template<typename dataType>
List<dataType>:: ~List(){
  clear();
}

template<typename dataType>
int List<dataType>:: size() const{
  return count;
}

template<typename dataType>
bool List<dataType>:: empty() const{
  if (count == 0)
    return true;
  else
    return false;
}

template<typename dataType>
void List<dataType>:: clear(){
  for(first; first->siguiente!=nullptr; first->siguiente = first)
    delete[] first;
}

template<typename dataType>
dataType & List<dataType>:: back(){
  if (empty()){
    throw runtime_error("Lista vacia");
  }
  return last->datos;
}

template<typename dataType>
dataType & List<dataType>:: front(){
  if (empty()){
    throw runtime_error("Lista vacia");
  }
  return first->datos;
}

template<typename dataType>
void List<dataType>:: push_back(dataType & rhs){
  Node_Cell *newNode_cell = new Node_Cell;
  newNode_cell->datos = rhs;

  if(empty()){
    newNode_cell->siguiente = nullptr;
    newNode_cell->anterior = nullptr;
  }else{
    newNode_cell->siguiente = nullptr;
    newNode_cell->anterior = last;
    last = newNode_cell;
  }
  count ++;
}

template<typename dataType>
void List<dataType>:: push_front(dataType & rhs){
  Node_Cell *newNode_cell = new Node_Cell;
  newNode_cell->datos = rhs;

  if(empty()){
    newNode_cell->siguiente = nullptr;
    newNode_cell->anterior = nullptr;
  }else{
    newNode_cell->anterior = nullptr;
    newNode_cell->siguiente = first;
  first = newNode_cell;
  }
  count ++;
}

template<typename dataType>
void List<dataType>:: pop_back(){
  Node_Cell *ultimo = new Node_Cell;
  ultimo = last->anterior;
  delete[] last;
  last = ultimo;
  last->siguiente = nullptr;
  count --;
}

template<typename dataType>
void List<dataType>:: pop_front(){
  Node_Cell *primero = new Node_Cell;
  primero = first->siguiente;
  delete[] first;
  first = primero;
  primero->anterior = nullptr;
  count --;
}

#endif
