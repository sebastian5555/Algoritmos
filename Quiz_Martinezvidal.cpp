#include<iostream>
#include<list>
using namespace std;

int howMany(list<int> L, int k){
  int cont;
  while(!L.empty()){
    if (L.front() == k){
      cont++;
    }
    L.pop_front();
  }
  return cont;
}

int main() {
  int array[] = {5,3,4,3,7,5,3,2,7,7,1};
  list<int> mylist(array,array);

  cout << "Ingrese el número a buscar: ";
  int n;
  cin >> n;

  cout << n << " está " << howMany(mylist, n)<< " veces.\n";
    return 0;
  }
