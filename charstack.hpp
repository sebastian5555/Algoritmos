#ifndef __charstack__hpp
#define __charstack__hpp
#include <vector>
#include <stdexcept>
using namespace std;


class CharStack{
private:
  vector<char> elements;

public:
  CharStack() {}
  ~ CharStack() {}

  int size();
  void clear();
  bool empty();
  char top();
  void push(char c);
  char pop();
};
#endif
