#include<iostream>
#include<vector>
#include <map>
using namespace std;


int main(){
  map<char,int> mymap;
  map<char,int>::iterator it;

  mymap['a'] = 10;
  mymap['b'] = 20;
  mymap['c'] = 30;
  mymap['d'] = 40;

  if(mymap.count('c'))
    cout << "Elements exists";

  it = mymap.find('c');
  cout << "Element " << it->first << "is" << it-> second << "\n";

  return 0;
}
