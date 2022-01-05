
#include<iostream>
#include<tuple>
using namespace std;

int main(){
   // tuple is a unique datatype similar to array except for the fact that they cant have duplicate 
  //  tuple <int , string> person(20,"Tim"); 
  //  cout << get<0>(person)<<endl;;
  //  get<0>(person) = 30;
  //  cout << get<0>(person)<<endl;
  // declaration of a tuple
  tuple < char , int , float> charles;
  // assigning values to a tuple 
  charles = make_tuple('C',19,1.75);
  // printing values of tuple 
  cout << "The innitial value of the tuple is: "<<endl;
  cout << get<0>(charles) << " " << get<1>(charles) << " " << get<2>(charles) << endl;

  // changing values of tuple 
  get<0>(charles) = 'B';
  get<2>(charles) = 1.65;
  cout << "The modified  value of the tuple is: "<<endl;
  cout << get<0>(charles) << " " << get<1>(charles) << " " << get<2>(charles) << endl;
}