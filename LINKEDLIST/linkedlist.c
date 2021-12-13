
#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;
//void insert_at_begin(int);
//void insert_at_end(int);
//void traverse();
//void delete_from_begin();
//void delete_from_end();
//int count = 0;

int main () {
  int i, data,position;

  for (;;) {
    printf("1. Insert an element at the beginning of linked list.\n");
    printf("2. Insert an element at the end of linked list.\n");
    printf("3. Insert Element at any position of a linked list");
    printf("4. Traverse linked list.\n");
    printf("5. Delete an element from beginning.\n");
    printf("6. Delete an element from end.\n");
    printf("7. Delete an element at a certain position");
    printf("8. Exit\n");

    scanf("%d", &i);

    if (i == 1) {
      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_begin(data);
      Print();
    }
//    else if (i == 2) {
//      printf("Enter value of element\n");
//      scanf("%d", &data);
//      insert_at_end(data);
//      Print();
//	}
//    else if (i == 3) {
//      printf("Enter value of element\n");
//      scanf("%d", &data);
//      printf("Enter position of element\n");
//      scanf("%d", &position);
//      insert_at_pos(data, position);
//      Print();
//  }
//    
//    else if (i == 4){
//      traverse();
//      Print();
//	}
//      
//    else if (i == 5){
//      delete_from_begin();
//      Print();
//	}
     
//    else if (i == 6){
//      delete_from_end();
//	  Print();	
//	}
//	else if (i == 7) {
//      printf("Enter value of element\n");
//      scanf("%d", &data);
//      printf("Enter value of element\n");
//      scanf("%d", &position);
//      delete_at_end(data,position);
//      Print();
//	}
//    else if (i == 8)
//      break;
//    else
//      printf("Please enter valid input.\n");
//  }

  return 0;
}

void Print(){
	struct node *ptr = start;
	while(ptr != NULL){
		printf("The element in the list are %d\n ", ptr->data);
		ptr = ptr->next;
	}
}

void insert_at_begin(struct node **head , int data){
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = NULL;
	
	ptr->next = *head;
	*head = ptr;
}

