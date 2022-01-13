#include<stdlib.h>
#include<stdio.h>
     
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
 
 
struct node
{
        int info;
        struct node *next;
};
struct node *head=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("n                MENU                             \n");
                printf("n 1.Create     \n");
                printf("n 2.Display    \n");
                printf("n 3.Insert at the beginning    \n");
                printf("n 4.Insert at the end  \n");
                printf("n 5.Insert at specified position       \n");
                printf("n 6.Delete from beginning      \n");
                printf("n 7.Delete from the end        \n");
                printf("n 8.Delete from specified position     \n");
                printf("n 9.Exit       \n");
                printf("n--------------------------------------\n");
                printf("Enter your choice:t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;
                        
                        case 9:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:n");
                exit(0);
        }
        printf("\nEnter the data value for the node\t :");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void display()
{       
        // this printing is done in an iterative way 
        struct node *ptr;
        if(head==NULL)
        {
                printf("\nList is empty:n");
                return;
        }
        else
        {
                ptr=head;
                printf("\nThe List elements are:n");
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->info );
                        ptr=ptr->next ;
                }
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                // we  print out of memory space because we can not something at the beginning of  something which does  not exist 
                printf("nOut of Memory Space:n");
                return;
        }
        printf("nEnter the data value for the node:t" );
        scanf("%d",&temp->info);
        // this is the  link of the  node we are about adding , so we will innitially declare  it ad null 
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else  
        // if something already existed  we  make sure that the innitial node that was at the head , now be pointed by the new node which will now become  our head 
        {
                temp->next=head;
                head=temp;
        }
}
void insert_end()
{
        // here  , we need another pointer  to be able to move  to end of the linked list 
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                return;
        }
        printf("nEnter the data value for the node:t" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        // we will make sure to use this pointer  to loop to the end of the  list so as to make  our new  node the tail of the  list 
        {
                ptr=head;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                return;
        }
        printf("nEnter the position for the new node to be inserted:t");
        scanf("%d",&pos);
        printf("nEnter the data value of the node:t");
        scanf("%d",&temp->info) ;
  
        temp->next=NULL;
        if(pos==0)   
        {
                // this permit us to change the link to respective nodes
                temp->next=head;
                head=temp;
        }
        else
        {
                for(i=0,ptr=head;i<pos-1;i++) { 
                        ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("nPosition not found:[Handle with care]n");
                                return;
                        }
                }
                
                // this permit us to change the link to respective nodes
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("nList is Empty:n");
                return;
        }
        else
        {
                ptr=head;
                head=head->next ;
                printf("nThe deleted element is :%dt",ptr->info);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("nList is Empty:");
                exit(0);
        }
        else if(head->next ==NULL)
        // this is when we have  just one node in our list 
        {
                ptr=head;
                head=NULL;
                printf("nThe deleted element is:%dt",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("nThe deleted element is:%dt",ptr->info);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("nThe List is Empty:n");
                exit(0);
        }
        else
        {
                printf("nEnter the position of the node to be deleted:t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=head;
                        head=head->next ;
                        printf("nThe deleted element is:%dt",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("nPosition not Found:n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("nThe deleted element is:%dt",ptr->info );
                        free(ptr);
                }
        }
}
