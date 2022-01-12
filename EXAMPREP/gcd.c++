

#include<iostream>
using namespace std;

int gcd(int a , int b){
  while (a != b)
  {
    if(a > b){
      a = a - b;
    }else {
      b = b -a ;
    }
  }
  cout << a ; 
}

int main(){
  int  a = 8; 
  // cout<<"Enter the first number: "<<endl;
  // cin >> a;
  int b  = 3;
  // cout<<"Enter the second number: "<<endl;
  // cin >> b;
  cout <<"The gcd of %d "<< a <<" and  %d "<< b<< " is " << gcd(a,b)<<endl;
}