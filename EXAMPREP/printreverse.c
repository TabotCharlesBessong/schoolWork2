



#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
};

void print(struct node* head){
  // we will make use of recursion 
  if(head == NULL) return ;
  print(head->next);
  printf("%d",head->data);
  
}

int  main(){
  struct node* head = NULL;
}