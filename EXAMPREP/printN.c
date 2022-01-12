

#include<stdio.h>

void display (int num){
  if(num)
    display(num-1);
  else
    return;
  printf("\n%d\n",num);
}

int main(){
  int limit;
  printf("Enter the number of terms to be printed\n");
  scanf("%d",&limit);
  display(limit);

  return 0;
}