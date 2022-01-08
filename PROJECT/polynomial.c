

#include<stdio.h>


// the structure above is a structure that enables us to create our node for each values of the polynomial 
struct node {
  float coef;
  int expo;
  struct node* link;
};

// now we are going to create the polynomial 
// we are going to use sorted linked  list 
// we will need an ordered linked list so we can do correct arithmetic operation 

struct node* create(struct node* head){
  int n; 
  int i;
  float coef;
  int expo;
  printf("Enter the number of terms: ");
  scanf("%d",&n);
  printf("Please enter the coefficient: ");
  scanf("%d",&i);
  // printf(" The value is %d",n);
  // int c = n * 3 ;
  // printf("%d",c);
  for(i = 0;i<n;i++){
    printf("Enter the coefficient for term %d: ", i+1);
    scanf("%f",&coef);
    printf("Enter the exponent for term %d: ", i+1);
    scanf("%f",&expo);
    head = insert(head,coef,expo);
  }
}

struct node* insert(struct node* head , int co , int ex){
  struct node* temp;
  struct node* newP = malloc(sizeof(struct node));
  newP->coef = co ;
  newP->expo = ex ;
  newP->link = NULL ; 
  if(head == NULL || ex > head->expo){
    newP->link = head;
    head = newP ;
  }else{
    temp = head;
    while(temp->link != NULL && temp->link->expo >  ex)
      temp = temp->link;
    newP->link = temp->link;
    temp->link = newP ; 
  }
  return head;
}

int main (){
  // printf("Hello world");
  // first step declare a node in the main function 
  struct node* head = NULL;
  printf("Enter the polynomials:\n ");
  head = create(head);
}

// we are going  to have a seperate function to create a node for each polynomial value 

