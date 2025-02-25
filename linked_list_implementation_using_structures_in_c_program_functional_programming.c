#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node* next;
};

int main()
{
  
    struct node* head;  
    struct node* newnode;
    struct node* temp;
    int choice=1;
    int choice1=1;
    int choice3=1;
    int choice4=1;
    int position;
    while(choice)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
   
    if(head==0){
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    printf("Do you want to continue(0,1): ");
    scanf("%d",&choice);
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf("Do you Want to insert a node at the beginning of the list ?(0,1): ");
    scanf("%d",&choice1);
    while(choice1)
    {
    temp=head;
    
    newnode=(struct node*)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    
    //to display inserted at beginning node
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf("Do you Want to insert a node at the beginning of the list ?(0,1): ");
    scanf("%d",&choice1);
    }
    //inserting element at the end
    printf("Do you want to insert node at the end ?(0,1)\n");
    scanf("%d",&choice3);
    while(choice3){
    temp=head;
    
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    
    //to display inserted at end of the node
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf("Do you want to insert node at the end ?(0,1)\n");
    scanf("%d",&choice3);
    
    }
    //to find length of linkedlist
    temp=head;
    int count=1;
    while(temp=NULL)
    {
        temp=temp->next;
        count++;
    }
    //
    
    printf("Do you want to insert node at any other position?(0,1): ");
    scanf("%d",&choice4);
    while(choice4)
    {
        printf("At which Position Do you want to insert?: ");
    scanf("%d",&position);
    if(position>count)
    {
        printf("Invalid Position! \n");
    }
    else{   
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        temp=head;
        int count1=1;
        while(count1!=position)
        {
            temp=temp->next;
            count1++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        //to display inserted at given position
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    }  
    }
    
    
    
    return 0; 
}
