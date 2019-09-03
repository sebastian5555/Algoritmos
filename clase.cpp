#include <iostream>
#include <sys/time.h>
using namespace std;

int fibonacci(int n){
  if(n<2){
    return n;
  }
  else{
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int additiveSeq(int f0, int f1, int n){
  if (n == 0) return f0;
  else if (n == 1) return f1;
  else{
    return additiveSeq(f1,f0+f1, n-1);
  }
}

double gettime(){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

bool ispalindrome(string str){
  int len = str.length();
  if (len <= 1){
    return true;
  }
  else{
    return (str[0] == str[len-1]) && ispalindrome(str.substr(1,len-2));
  }
}
bool isSubstringPalindrome(string str, int p1, int p2){
  if(p1 >= p2){
    return true;
  }
  else{
    return str[p1]==str[p2] && isSunstringPalindrome(str, p1+1, p2-1);
  }
}

int main(){
  cout << ispalindrome("matam")<< "\n";
  cout << gettime()<< "\n";
  return 0;
}
