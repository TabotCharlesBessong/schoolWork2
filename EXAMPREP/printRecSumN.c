

#include<stdio.h>

int sum(int num){
  if(num)
    return (num + sum(num - 1));
  else
    return 0 ;
}

int main(){
  int c = 30;
  printf("The sum of 1st %d values is %d \n", c , sum(c));
  return 0;
}