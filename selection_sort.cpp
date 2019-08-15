#include <iostream>
#include <vector>
#include "functions.hpp"
using namespace std;



void selection_sort(vector<int>& v){
  for (int i = 0; i < v.size()-1; i++){
    int min_id = i;
    for (int j = i+1; j < v.size(); ++j){
      if (v[j] < v[min_id])
        min_id = j;
      }
      swap (i,min_id,v);
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
    generate_ordered_vector(size,vec,rng,true);
    //get initial time
    double tstart = gettime();

    selection_sort(vec);

    //final time
    double tstop = gettime();
    tot_time += tstop-tstart;
  }
  cout << "Time taken = " << tot_time / times << endl;


  return 0;
}
