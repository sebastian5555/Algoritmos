#include <iostream>
#include <vector>
#include "functions.hpp"
using namespace std;

bool is_sorted(const vector<int>& v){
  for(int i = 0; i < v.size()-1; ++i){
    if(v[i] > v[i+1])
      return false;
  }
  return true;
}

void shuffle(vector<int>& v, minstd_rand0& rng){
  //two random numbers
  int num1 = int(v.size() * ( double(rng()) / rng.max() ));
  int num2 = int(v.size() * ( double(rng()) / rng.max() ));

  //swap the elements
  swap(num1, num2, v);
}

void bogosort(vector <int>& v, minstd_rand0& rng){
  while (!is_sorted(v)){
    shuffle(v, rng);
  }
}

int main(){
  vector<int> first= {12,34,54,32,11,4,5,74,10,13};
  is_sorted(first);

  int times = 100;
  int size = 12;
  vector<int> vec;

  //random number generator
  unsigned seed = 123;
  minstd_rand0 rng(seed);

  generate_vector(size, vec, rng);

  return 0;
}
