
#include<iostream>
#include<set>
using namespace std;

int main(){
  // a set is an unordered collectoon of unique elements
  // set<char> s1 = {'C','D','E','D','C'};
  // s1.insert('B');
  // s1.erase('E');

  // if(s1.find('C') == s1.end()){
    // cout <<"Could not find C"<<endl;
  // }else{
    // cout<<"Found C"<<endl;
  // }

  // for(auto itr = s1.begin();itr != s1.end(); ++itr){
    // cout<<*itr<<endl; 
  // }

  string test = "hels";
  string find = "hello";
  set<char> occur ;

  set<char> findLetter;

  for(int i = 0;i< findLetter.size();++i){
    char letter = find[i];
    findLetter.insert(letter);
  }
  for(int i = 0;i<test.length();i++){
    char letter = test[i];
    findLetter.erase(letter);
  }
  if(findLetter.size() > 0){
    cout<<"No it does not have all letters!";
  }
  else{
    cout<<"Yes it does";
  }

  // for(int i= 0;i<test.length();++i){
  //   char letter = test[i];
  //   occur.insert(letter);
  // }
  // for(auto itr = occur.begin(); itr != occur.end();++itr){
  //   cout << *itr <<endl;
  // }

}
