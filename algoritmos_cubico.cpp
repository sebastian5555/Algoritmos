#include <iostream>
#include <vector>
#include "functions.hpp"
using namespace std;

int maxSubSum1(const vector<int>& a){
  int maxSum = 0;
  for (int i = 0; i < a.size(); ++i){
    for(int j = i; j < a.size(); ++j){
      int thisSum = 0;

      for (int k = i; k <= j; ++k)
        thisSum += a[k];

      if (thisSum > maxSum)
        maxSum = thisSum;
    }
  }
  return maxSum;
}
int main(){
  int times = 100;
  int size = 13;
  vector<int> vec;
  unsigned seed = 123;
  minstd_rand0 rng(seed);
  generate_vector(size, vec, rng);
  double tot_time = 0;
  int p;
  for(int n = 0; n < times; ++n){
    double tstart = gettime();
    p = maxSubSum1(vec);
    double tstop = gettime();
    tot_time += tstop-tstart;
  }

  cout << "Time taken = " << tot_time / times << endl;
  cout << "\n" << p << "\n";
  return 0;

 }
