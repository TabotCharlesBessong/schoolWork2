#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <malloc.h>
 struct Poly_Node
 {
     int coef;
     int expo;
     struct Poly_Node *next;
 };
struct Poly_Node *poly1=NULL,*poly2=NULL,*poly=NULL;
void create_poly(struct Poly_Node *P){
    char choice;
    do{

        printf("Enter Coefficient:\n");
        scanf("%d",&P->coef);
        printf("Enter Exponent:\n");
        scanf("%d",&P->expo);
        P->next=(struct Poly_Node*)malloc(sizeof(struct Poly_Node));
         P=P->next;
        P->next=NULL;
    printf("Enter 'y' to continue:\n");
    choice=getch();
    }while(choice=='y' || choice=='Y');
 

}
void display_poly(struct Poly_Node *P){
    printf("\t\t\t\t\t\t\t\t");
     while(P->next!=NULL){
        printf("%dx^%d",P->coef,P->expo);
        P=P->next;
        if(P->next!=NULL&&P->coef>=0){
            printf(" + ");
        }
     }

}
int degree_poly(struct Poly_Node *P){
    int degree=P->expo;
       while(P->next!=NULL){
        if(degree>=P->expo){
            degree=degree;
        }
        else{
            degree=P->expo;
        }
        P=P->next;
       }
       return degree;

}

void add_poly(struct Poly_Node *poly1,struct Poly_Node *poly2,struct Poly_Node *poly)
{
     while(poly1->next &&  poly2->next)
     {
      if(poly1->expo>poly2->expo)
      {
       poly->expo=poly1->expo;
       poly->coef=poly1->coef;
       poly1=poly1->next;
       }
      else if(poly1->expo<poly2->expo)
      {
       poly->expo=poly2->expo;
       poly->coef=poly2->coef;
       poly2=poly2->next;
       }
      else
      {
       poly->expo=poly1->expo;
       poly->coef=poly1->coef+poly2->coef;
       poly1=poly1->next;
       poly2=poly2->next;
       }
      poly->next=(struct Poly_Node *)malloc(sizeof(struct Poly_Node));
      poly=poly->next;
      poly->next=NULL;
     }
     while(poly1->next || poly2->next)
     {
      if(poly1->next)
      {
       poly->expo=poly1->expo;
       poly->coef=poly1->coef;
       poly1=poly1->next;
       }
      if(poly2->next)
      {
       poly->expo=poly2->expo;
       poly->coef=poly2->coef;
       poly2=poly2->next;
       }
       poly->next=(struct Poly_Node *)malloc(sizeof(struct Poly_Node));
       poly=poly->next;
       poly->next=NULL;
       }
}
int eval_poly(struct Poly_Node *P,int n){
    int result=0;
    if(P->next==NULL){
  return P->coef * pow(n,P->expo);
    }
    else{
        while(P->next!=NULL){
                if(P->expo==0){
                    result=result + P->coef;
                }
                else{
                     result=result + P->coef * pow(n,P->expo);
                }
                P=P->next;
        }
        return result;
    }
}
void multiply_poly(struct Poly_Node *poly1,struct Poly_Node *poly2,struct Poly_Node *poly){

 while(poly1->next &&  poly2->next)
     {
      if(poly1->expo>poly2->expo)
      {
       poly->expo=poly1->expo;
       poly->coef=poly1->coef;
       poly1=poly1->next;
       }
      else if(poly1->expo<poly2->expo)
      {
       poly->expo=poly2->expo;
       poly->coef=poly2->coef;
       poly2=poly2->next;
       }
      else
      {
       poly->expo=poly1->expo + poly2->expo;
       poly->coef=poly1->coef*poly2->coef;
       poly1=poly1->next;
       poly2=poly2->next;
       }
      poly->next=(struct Poly_Node *)malloc(sizeof(struct Poly_Node));
      poly=poly->next;
      poly->next=NULL;
     }
     while(poly1->next || poly2->next)
     {
      if(poly1->next)
      {
       poly->expo=poly1->expo;
       poly->coef=poly1->coef;
       poly1=poly1->next;
       }
      if(poly2->next)
      {
       poly->expo=poly2->expo;
       poly->coef=poly2->coef;
       poly2=poly2->next;
       }
       poly->next=(struct Poly_Node *)malloc(sizeof(struct Poly_Node));
       poly=poly->next;
       poly->next=NULL;
       }
}

 int main(){
char choice;
int option;
int x;
do{
   poly1=(struct Poly_Node*)malloc(sizeof(struct Poly_Node));
   poly2=(struct Poly_Node*)malloc(sizeof(struct Poly_Node));
   poly=(struct Poly_Node*)malloc(sizeof(struct Poly_Node));
do{
   printf("ENTER\n"
          "1.Create P(X)\n"
          "2.Create Q(X)\n"
          "3.Display P(X) and Q(X)\n"
          "4.Display Degree of P(X) and Q(X)\n"
          "5.Evaluate P(x)\n"
          "6.Evaluate Q(x)\n"
          "7.ADD P(X) AND Q(X) and Display Result\n"
          "8.Multiply P(X) and Q(X)and Display Result\n"
          "9.EXIT\n"
          );
   scanf("%d",&option);
   switch(option){
case 1:
   printf("Enter Polynomial P(X)\n");
   create_poly(poly1);
   break;
case 2:
   printf("Enter Polynomial Q(X)\n");
   create_poly(poly2);
   break;
case 3:
   printf("\nP(X) = ");
   display_poly(poly1);
   printf("\n");
   printf(" \nQ(X) = ");
   display_poly(poly2);
   printf("\n");
   break;
case 4:
   printf("\n");
   printf("P(X) is of degree:: %d", degree_poly(poly1));
   printf("\n");
   printf("Q(X) is of degree:: %d", degree_poly(poly2));
   printf("\n");
   break;
case 5:
     printf("Enter X\n");
     scanf("%d",&x);
     printf("P(%d) = %d",x, eval_poly(poly1,x));
     printf("\n");
     break;
case 6:
     printf("Enter X\n");
     scanf("%d",&x);
     printf("Q(%d) = %d",x, eval_poly(poly2,x));
     printf("\n");
     break;
case 7:
   add_poly(poly1,poly2,poly);
   printf("P(X) + Q(X) = ");
   display_poly(poly);
   printf("\n");
   break;
case 8:
   multiply_poly(poly1,poly2,poly);
   printf("P(X) * Q(X) = ");
   display_poly(poly);
   printf("\n");
   break;
case 9:
    break;
default:
    printf("please Enter A Valid Option\n");
   }
}while(option!=11);
  printf("Enter 'y' to use two different Polynomials\n");
  choice=getch();
}
while(choice=='y' || choice=='Y');

}
