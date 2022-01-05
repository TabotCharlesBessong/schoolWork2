
#include<iostream>
#include<tuple>
using namespace std;

int main(){

  int i_val ;
  char ch_val;
  float f_val;

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
  
  // tuple size 
  cout <<"The size of tuples is :"<<endl;
  cout << tuple_size<decltype(charles)>::value << endl;
  

  tuple <int , char, float> tup1(20,'t',17.75);
  tuple <int , char , float > tup2(23,'j',16.67);
  // ignoring some vlues in tup1 
  tie(i_val,ch_val,f_val) = tup1;

  cout << "The unpack value of the tuple without ignore is"<<endl;
  cout << i_val <<" " << ch_val <<" " << f_val <<endl;

  // ignoring some vlues in tup1 
  tie(i_val,ignore,f_val) = tup1;
  cout << "The unpack value of the tuple with ignore is"<<endl;
  cout << i_val <<" " << f_val <<endl;

  cout << "The value of the first tuple before swapping is : "<<endl;
  cout << get<0>(tup1) << " "<< get<1>(tup1) << " " << get<2>(tup1) << endl;
  cout << "The value of the second tuple before swapping is : "<<endl;
  cout << get<0>(tup2) << " "<< get<1>(tup2) << " " << get<2>(tup2) <<endl;

  tup1.swap(tup2);

  cout << "The value of the first tuple after swapping is : "<<endl;
  cout << get<0>(tup1) << " "<< get<1>(tup1) << " " << get<2>(tup1) << 
  endl;
  cout << "The value of the second tuple after swapping is : "<<endl;
  cout << get<0>(tup2) << " "<< get<1>(tup2) << " " << get<2>(tup2) 
  <<endl;

  // concatenating tuple in c++ 
  auto tup3 = tuple_cat(tup1,tup2);
  cout << "The values of the new tuple is "<<endl;
  cout << get<0>(tup3) << " " << get<1>(tup3) << " ";
  cout << get<2>(tup3) << " " << get<3>(tup3) << " ";
  cout << get<4>(tup3) << " " << get<5>(tup3) << endl;

}