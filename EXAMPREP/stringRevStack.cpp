

#include<bits/stdc++.h>
using namespace std;

void stringRev(string &str){
  stack<char> s;
  for(int i = 0; i < str.length();i++){
    s.push(str[i]);
  }
  for(int i = 0; i< str.length();i++){
    str[i] = s.top();
    s.pop();
  }
}

int main(){
  string str = "alberteinstein";
  stringRev(str);
  cout<< str;
  return 0 ;
}