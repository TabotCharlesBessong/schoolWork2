#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

//void addAtBeg(struct node **head, int data){
////	int data;
//	struct node *ptr = malloc(sizeof(struct node));
//	ptr->data = data;
//	ptr->link = NULL;
//	
//	ptr->link = *head;
//	*head = ptr;
//}

//void addAtEnd(struct node *head, int data){
//	struct node *ptr , *temp;
//	ptr = head;
//	temp = (struct node*)malloc(sizeof(struct node));
//	
//	temp->data = data;
//	temp->link = NULL;
//	
//	while(ptr->link != NULL){
//		ptr = ptr->link;
//	}
//	ptr->link = temp;
//}

void addAtPos(struct node* head,int data,int position){
	struct node *ptr = head;
	struct node *ptr2 = malloc(sizeof(struct node));
	ptr2->data = data;
	ptr2->link = NULL;
	
	position--;
	while(position !=1){
		ptr = ptr->link;
		position--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;
}

int main(){
	struct node *ptr = malloc(sizeof(struct node));
	struct node *head = malloc(sizeof(struct node));
	head->data = 76;
	head->link = NULL;
//	int position = 4;
//	int data = 67;
//	addAtEnd(head,87);
//	addAtBeg(&head,65);
//	addAtEnd(head,45);
	addAtPos(head,32,1);
	addAtPos(head,58,3);
	addAtPos(head,16,2);
//	addAtPos(head,position,data);
//	addAtBeg(&head,43);
	
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	return 0;
}
