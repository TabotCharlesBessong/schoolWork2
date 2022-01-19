

#include <iostream>
using namespace std;

int main() {
  int n1, n2, hcf,lcm;
  cout << "Enter two numbers: ";
  cin >> n1 >> n2;
  // int n1 = 15, n2 = 35, hcf;

  // swapping variables n1 and n2 if n2 is greater than n1.
  if ( n2 > n1) {   
    int temp = n2;
    n2 = n1;
    n1 = temp;
  }
    
  for (int i = 1; i <=  n2; ++i) {
    if (n1 % i == 0 && n2 % i ==0) {
      hcf = i;
    }
  }

  lcm = (n1 * n2) / hcf ; 
  cout << "HCF = " << hcf<<endl;
  cout << "LCM = " << lcm<<endl;
  return 0;
}