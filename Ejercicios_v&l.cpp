#include<iostream>
#include<vector>
using namespace std;
void funcion(vector<int> n, vector<int> m ){
  vector <int> final(10);
  unsigned sz = final.size();
  for (unsigned int k = 0; k < sz; k++){
        final[k] = n[k] + m[k];
  }
  for (unsigned int k = 0; k < sz; k++){
    cout << "" << final[k];
    cout << "\n";
  }
}

int main(){
  vector<int> n(9);
  vector<int> m(9);
  unsigned sz = n.size();
  unsigned sz2 = m.size();
  for (unsigned int i = 0; i < sz; i++){
    n[i] = i;
  }
  for (unsigned int j = 0; j < sz2; j++){
    m[j] = 3;
  }
  funcion(n,m);

  return 0;
}
