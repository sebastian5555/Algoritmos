#include <iostream>
#include <vector>
#include "functions.hpp"
using namespace std;

void  bubble_sort(vector<int>& v){
  bool swap_used = true;
  while(swap_used) {
    swap_used = false;
    for (int i = 0; i< v.size()-1; ++i){
      if(v[i]> v[i+1]) {
        swap(i,i+1,v);
        swap_used = true;
      }
    }
  }
}


int main(){
  int times = 100;
  int size = 1e3;
  vector<int> vec;

  //random number generator
  unsigned seed = 123;
  minstd_rand0 rng(seed);
  double tot_time = 0;
  for (int n = 0; n < times; ++n){
    generate_ordered_vector(size,vec,rng,false);

    //get initial time
    double tstart = gettime();

    bubble_sort(vec);

    //final time
    double tstop = gettime();

    tot_time += tstop-tstart;
  }
  cout << "Time taken = " << tot_time / times << endl;

  return 0;
}
