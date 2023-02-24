#include<iostream>
using namespace std;

int main(){
  // Pointers are variables that store the address of other variables
  int a;
  int *p;
  p = &a;
  cout<<"The address of the variable "<<a<<" is "<<p<<endl;
  cout<<"The address of the variable "<<p<<" is "<<*p<<endl;
  a = 10;
  cout<<"The value of a before dereferencing is: "<<a<<endl;
  // dereferencing
  *p = 12;
  int b = *p;
  cout<<"The value of a after dereferencing is: "<<b<<endl;

  // pointer arithmetic
  cout<<"Address P is: "<<p<<endl;
  cout<<"Size of the int is: "<<sizeof(int)<<endl;
  cout<<"Address P + 1 is: "<<p+1<<endl;
  return 0;
}