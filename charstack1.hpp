#ifndef __charstack__hpp
#define __charstack__hpp
#include <stdexcept>
using namespace std;

const int INITIAL_CAPACITY = 10;

class CharStack {
private:
  char *elements;
  int capacity;
  int count;

public:
  CharStack();
  ~ CharStack();

  int size();
  void clear();
  bool empty();
  char top();
  void expandCapacity();
  void push(char c);
  char pop();
};
#endif
