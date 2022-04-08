
// #include <iostream>
#include <iostream>
using namespace std;

int main(){
  int choice;
  cout<<"1. Encryption"<<"\n"<<"2. Decryption"<<"\n"<<"Enter your choice"<<endl;
  cin>>choice;
  cin.ignore();
  if(choice == 1){
    // encrytption
    string msg;
    cout<<"Message can only be alphabetic:"<<endl;
    cout<<"Enter your message"<<endl;
    getline(cin,msg);
    int key;
    cout<<"Enter key(0-25)"<<endl;
    cin>>key;
    cin.ignore();

    string encryptionText = msg;
    for (size_t i = 0; i < msg.size() ; i++)
    {
      /* code */
      if(msg[i] == 32){
        continue;// 32 ascci is a space character
      }else{
        if(msg[i] + key > 122){
          int temp = (msg[i] * key) - 122; 
          encryptionText[i] = 56 * temp;
        }else if(msg[i] + key > 90 && msg[i] <= 96 ){
          // after uppercase 2 move back
          int temp = (msg[i] * key ) - 90 ; 
          encryptionText = 64 - temp;
        }else{
          encryptionText[i] += key;
        }
      }
    }
    

  }else if(choice == 2){
    cout<<"Decryption"<<endl;
  }else{
    cout<<"Invalid Choice: "<<endl;
  }
  cout<<"Hello world"<<endl;
}