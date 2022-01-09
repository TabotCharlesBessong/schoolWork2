

#include<stdio.h>
#include<stdlib.h>


// the structure above is a structure that enables us to create our node for each values of the polynomial 
struct node {
  float coef;
  int expo;
  struct node* link;
};

// now we are going to create the polynomial 
// we are going to use sorted linked  list 
// we will need an ordered linked list so we can do correct arithmetic operation 

struct node* insert(struct node* head , float co , int ex){
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

struct node* create(struct node* head){
  int n; 
  int i;
  float coef;
  int expo;
  printf("Enter the number of terms: ");
  scanf("%d",&n);
  // printf("Please enter the coefficient: ");
  // scanf("%d",&i);
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



// function to print our polynomial 
void print(struct node* head){
  if(head == NULL)
    printf("No polunomial available");
  else {
    struct node* temp = head;
    while(temp != NULL){
      printf("(%.1fx^%d)",temp->coef , temp->expo);
      temp = temp->link;
      if(temp != NULL)
        printf(" + ");
      else
        printf("\n");
    }
  }
}

// now we are going to create a function for addition of the polynomial . 
// what is our strategy , since we want to add values of same coeficient and the order to which polynomial we first add do not matter , 
// we will iterate through one polynomial while it is != null 
// again iterate through the other , 
// if two exponents are same , we add them , 
// if the expo of the first is greater than thr first  , you push it   to the result 
// else i.e if less than you push that of the second 
// also if the first polynomial has reached null , we add that  of the next polynomail , same goes with the second polynomial 
// so this will be  our approach 

void addition (struct node* head , struct node* head2){
  struct node* ptr1 = head;
  struct node* ptr2 = head2;
  struct node* head3 = NULL;
  while(ptr1 != NULL && ptr2 != NULL){
    if(ptr1->expo == ptr2->expo){
      head3 = insert(head3, ptr1->coef + ptr2->coef , ptr1->expo);
      ptr1 = ptr1->link;
      ptr2 = ptr2->link;
    }else if(ptr1->expo > ptr2->expo){
      head3 = insert(head3,ptr1->coef, ptr1->expo);
      ptr2 = ptr2->link;
    }else{
      head3 = insert(head3 , ptr2->coef , ptr2->expo);
      ptr2 = ptr2->link;
    }
  }
  while(ptr1 != NULL){
    head3 = insert(head3 , ptr1->coef, ptr1->expo);
    ptr1 = ptr1->link;

  }
  while(ptr2 != NULL){
    head3 = insert(head3 , ptr2->coef , ptr2->expo);
    ptr2 = ptr2->link;
  }
  printf("Added polynomial is : ");
  print(head3);
}

int main (){
  // printf("Hello world");
  // first step declare a node in the main function 
  // struct node* head = NULL;
  // printf("Enter the polynomials:\n ");
  // head = create(head);

  // printing the polynomial 
  // print(head);
  // return 0;

  struct node* head1 = NULL;
  struct node* head2 = NULL;
  printf("Enter the first polynomial \n ");
  head1 = create(head1);
  printf("Enter the second polynomial \n ");
  head2 = create(head2);

  addition(head1, head2);
  return 0; 
}

// we are going  to have a seperate function to create a node for each polynomial value 

