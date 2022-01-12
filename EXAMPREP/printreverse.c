

// This program print  linked list in a reverse order using the recursive approach 

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
};

void print(struct node* head){
  // we will make use of recursion 
  if(head == NULL) return ;
  // since we are suing the address  of each node  , as we call this function before printing any values , we get to print  the values in reverse order  
  print(head->next);
  printf("%d",head->data);
  
}

int  main(){
  struct node* head = NULL;
}