
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


-------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <vector>

int main(){
std::stack<int> mystack;
  for (int i = 0; i < 5; ++i) mystack.push(i);
  std::cout << "Popping out elements...";

  while (!mystack.empty()) {
    std::cout << ' ' << mystack.top();
    mystack.pop();
  }
  std::cout << "\n";
  return 0;
}

--------------------------------------------------------------------
 #include <iostream>
#include <stack>
#include <vector>

int main(){
  std::stack<int> mystack;
  mystack.push(10);
  mystack.push(20);
  mystack.top() -= 5;
  std::cout << "mystack.top() is now " << mystack.top() << '\n';
  return 0;
}
