#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
  vector<int> myvector(2, 200);
  stack<int> first; // empty stack
  stack<int,std::vector<int>> second(myvector);
  cout << "size of first: " << first.size() << '\n';
  cout << "size of second: " << second.size() << '\n';
return 0;
}
