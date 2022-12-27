#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;
void creatlist(int);
void add(struct node*,int ,int);
void print(){
    struct node *temp;
    if(head==NULL)
    printf("list is empty");
    else{
        temp=head;
        printf("Data:\n");
        while(temp!=NULL){
            printf(" %d\n",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    int n,data,pos;
    printf("enter the total number of nodes: ");
    scanf("%d",&n);
    creatlist(n);
    printf("\ndata in the list: ");
    print();
    printf("\nenter the data to add to the list");
    scanf("%d",&data);
    printf("\nenter the position to add: ");
    scanf("%d",&pos);
    add(head,data,pos);
    printf("\ndata in the list: \n");
    print();
    return 0;
}
void creatlist(int n)
{
    struct node *newnode, *temp;
    int data,i;
    head=(struct node *)malloc(sizeof(struct node));
    if (head==NULL)
        printf("\nempty");
    else{
        printf("enter the data of node 1");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;

        for(i=2;i<=n;i++){
            newnode=(struct node*)malloc(sizeof(struct node));
            if (newnode==NULL){
                printf("\nempty");
                break;
            }
            else{
                printf("enter the data of %d:",i);
                scanf("%d",&data);
                newnode->data=data;
                newnode->next=NULL;
                temp->next=newnode;
                temp=temp->next;
            }
        }
        printf("\nsingly linked lidt created successfully\n");
    }
}
void add(struct node* head,int data,int pos){
    struct node *ptr=head;
    struct node *ptr2=malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->next=NULL;
    pos--;
    while(pos!=1){
        ptr=ptr->next;
        pos--;
    }
    ptr2->next=ptr->next;
    ptr->next=ptr2;

    }
