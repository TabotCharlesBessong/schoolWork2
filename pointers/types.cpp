
#include<iostream>
using namespace std;

int main(){
  int a = 1025;
  int *p;
  p = &a;
  cout<<"Size of integer is"<<sizeof(int)<<"bytes"<<endl;
  cout<<"Address = "<<p<<", value = "<<*p<<endl;

  char *p0;
  p0 = (char*)p;
  cout<<"Size of integer is"<<sizeof(int)<<"bytes"<<endl;
  cout<<"Address = "<<p0<<", value = "<<*p0<<endl;
  // 1025 = 00000000 00000000 00000100 00000001

  // void pointers
  void *p1;
  p1 = p;
  cout<<"Address = "<<p1<<endl;
}
