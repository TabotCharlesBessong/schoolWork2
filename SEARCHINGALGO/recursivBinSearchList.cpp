
#include<stdio.h>
#include<stdlib.h>
struct Node{
   int data;
   struct Node* next;
};
Node *newNode(int y){
   struct Node* temp = new Node;
   temp->data = y;
   temp->next = NULL;
   return temp;
}
struct Node* mid_node(Node* start, Node* last){
   if (start == NULL)
      return NULL;
   struct Node* slow = start;
   struct Node* fast = start -> next;
   while (fast != last){
      fast = fast -> next;
      if (fast != last){
         slow = slow -> next;
         fast = fast -> next;
      }
   }
   return slow;
}
struct Node* binarySearch(Node *head, int value){
   struct Node* start = head;
   struct Node* last = NULL;
   do{
      Node* mid = mid_node(start, last);
      if (mid == NULL)
         return NULL;
      if (mid -> data == value)
         return mid;
      else if (mid -> data < value)
         start = mid -> next;
      else
         last = mid;
   }
   while (last == NULL || last != start);
      return NULL;
}
int main(){
   Node *head = newNode(54);
   head->next = newNode(19);
   head->next->next = newNode(28);
   head->next->next->next = newNode(33);
   head->next->next->next->next = newNode(47);
   head->next->next->next->next->next = newNode(76);
   head->next->next->next->next->next->next = newNode(81);
   head->next->next->next->next->next->next->next = newNode(88);
   int value = 7 ;
//   printf("Enter the value you are looking for\n");
//   scanf("%d",value);
   if (binarySearch(head, value) == NULL)
      printf("Value is not present in linked list\n");
   else
      printf("The value  is present in linked list\n");
   return 0;
}
