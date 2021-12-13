#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};
//struct node *head = malloc(sizeof(struct node));

int main(){
	int n;
	printf("Enter a number for your linked list: \n");
	scanf("%d",&n);
	
	int b;
	printf("Enter a number for your linked list second element : \n");
	scanf("%d",&b);
	
	struct node *head = malloc(sizeof(struct node));
	head->data = n;
	head->link = NULL;
	printf("\nThe element of the linked list is %d\n",head->data);
	
	struct node *current = malloc(sizeof(struct node));
	current->data = b;
	current->link = NULL;
	head->link = current;
	
	printf("\nThe second element in the linked list is %d",current->data);
	
	int c;
	printf("Enter a number for your linked list third element: \n");
	scanf("%d",&c);
	
	current = malloc(sizeof(struct node));
	current->data = c;
	current->link = NULL;
	
	printf("\nThe third element linked list is %d",current->link->data);
	
	return 0;
}
