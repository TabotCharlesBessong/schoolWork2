#include<iostream>
#include<vector>
using namespace std;

int main(){
  // vectors are sequence containers representing arrays that can dynamically  change in size 
  vector<int> v1 = {1,2,3,4};
  cout << v1[1]<<endl;
  cout << v1.front()<<endl;
  cout << v1.back()<<endl;
  cout << v1.size()<<"  size"<<endl;
  cout << v1.capacity()<<endl;
  // .capacity is the number of elemebt it can hold , .size the number of element it it is currently holding
  v1.push_back(9);
  v1.insert(v1.begin(),13);
  v1.push_back(8);
  v1.push_back(7);
  v1.push_back(6);
  cout << v1.capacity()<<endl;
  cout << v1.size()<<endl;
  // v1.push_back(5);
  v1.pop_back();
  v1.pop_back();
  v1.pop_back();
  v1.pop_back();
  v1.pop_back();
  v1.shrink_to_fit();
  cout << v1.capacity()<<endl;
  cout << v1.size()<<endl;

}