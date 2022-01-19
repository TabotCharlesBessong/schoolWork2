#include<iostream>
using namespace std;

int main (){
  int a , b , temp , hcf , lcm , n1, n2; 
  cout<<"Enter 2  numbers: "<<endl;
  cin>>a>>b>>endl;
  n1 = a;
  n2 = b ;
  while(b!=0){
    temp = b ;
    b = a % b;
    a   = temp;
  }
  hcf = a;
  lcm = (a * b)/hcf ; 
  cout << "The HCF  is = "<<hcf<<endl;
  cout << "The LCM is  = "<<lcm<<endl;
}