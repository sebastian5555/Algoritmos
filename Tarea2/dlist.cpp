#include "dlist.hpp"

template<typename dataType>
List<dataType>:: List(){
  count = 0;
  first->anterior = nullptr;
  last->siguiente = nullptr;
}

List:: List(const List & other){

}

template<typename dataType>
List<dataType>:: ~List(){
  for(last; last != nullptr; last = last->siguiente){
    delete last;}

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
  count = 0;
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
}

template<typename dataType>
void List<dataType>:: pop_back(){
  delete[] last;
  count--;
}

template<typename dataType>
void List<dataType>:: pop_front(){
  delete[] first;
  count--;
}
