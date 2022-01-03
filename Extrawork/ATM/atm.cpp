#include<iostream>
using namespace std;

void showMenu (){
  cout<<"**************Menu***********"<<endl;
  cout<<"1 Check Balance"<<endl;
  cout<<"2 Deposit"<<endl;
  cout<<"3 withdraw"<<endl;
    cout<<"**************((())))***********"<<endl;
}

int main (){
    // show menu 
  showMenu();
  // get options from user 
  int option;
  double balance = 500;
  
  cout <<"Option: ";
  cin >>option ;
  switch(option){
    // check balance 
    case 1: 
      cout<<"Balance is: "<<"$"<<balance<<endl;
      break;
    // deposit 
    case 2:
      cout<<"Deposit amount: ";
      double depositAmount ;
      cout <<"Enter amount you wish to deposit"<<endl;
      cin>> depositAmount;
      balance += depositAmount;break ;

      case 3:
        cout<<"Withdrawal amount: ";
        double withdrawAmount ;
        // cout <<"Enter amount you wish to deposit"<<endl;
        cin>> withdrawAmount;
        if(withdrawAmount < balance){
          balance -= withdrawAmount;break ;
        }
          
        else{
          cout<<"Not enough fund";
        }
          
  }

  

  // withdraw 


  return 0;
}