#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
  queue<string> myqueue;
  string mystr;
  cout << "Ingrese su nombre: \n";
  do{
    cin >> mystr;
    myqueue.push(mystr);
  }while(mystr != "end");

  while (!myqueue.empty()){
    cout << "serving " << myqueue.front() << '\n';
    myqueue.pop();
  }
  return 0;
}
