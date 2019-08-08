#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
  set <char> myset;
  set <char>:: iterator it;

  string mystr;
  myset.insert('.');
  myset.insert(',');
  myset.insert('?');
  myset.insert(';');
  cout << "Ingrese una frase :";
  getline (cin, mystr);
    for (unsigned i= 0; i < mystr.length(); ++i){
      if (myset.count(mystr.at(i)) != 0)
        cout << " is an element of myset.\n";
      else
        cout << " is not an element of myset.\n";
  }
  return 0;
}
