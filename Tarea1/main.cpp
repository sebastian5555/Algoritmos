#include "simple_vector.hpp"


int main() {
  SimpleVec myvec;

  //Initialize the vector
  for(int i = 0; i < 20; i++)
    myvec.push(i);

  //iterate with index
  cout << "Going through the vector with the index:\n";
  for(int i = 0; i < 20; i++)
    cout << myvec.retrieve(i) << " ";
  cout << endl;

  //Declare an iterator
  SimpleVec::iterator it = myvec.begin();

  //iterate with iterator
  cout << "Going through the vector with the iterator:\n";
  for(it = myvec.begin(); it != myvec.end(); it++)
    cout << *it << " ";
  cout << endl;

  //Go to the 3rd element
  it = myvec.begin();
  for(int i = 0; i < 3; i++)
    ++it;
  //Change the element
  *it = 300;
  //Delete the last 3 elements
  for(int i = 0; i < 3; i++)
    myvec.erase(myvec.size()-1);


  //iterate with iterator
  cout << "Going through the vector with the iterator:\n";
  for(it = myvec.begin(); it != myvec.end(); it++)
    cout << *it << " ";
  cout << endl;

  //Testing prefix/postfix operators
  SimpleVec::iterator it2 = myvec.begin();
  SimpleVec::iterator it3 = myvec.begin();

  cout << "*it++: " << *it2++
       << " *it: " << *it2 << endl;
  cout << "++*it: " << *++it3
       << " *it: " << *it3 << endl;


  return 0;
}
