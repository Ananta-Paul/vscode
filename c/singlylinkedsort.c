#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* head=NULL;

void creatlist(int n)
{
    struct node *newnode, *temp;
    int data,i;
    head=(struct node *)malloc(sizeof(struct node));
    if (head==NULL)
        printf("\nempty");
    else{
        printf("enter the data of node 1:");
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
                printf("enter the data of node %d:",i);
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
void sort(struct node* head){
    struct node* i;
    struct node* j;
    int t;
    i=head;
    while(i!=NULL){
        j=i->next;
        while(j!=NULL){
        if (i->data>j->data)
        {
            t=i->data;
            i->data=j->data;
            j->data=t;
        }
        j=j->next;
        }
        i=i->next;
    }
    
}
struct node* rev(struct node* head){
    struct node* i;
    struct node* j;
    int t;
    i=head;
    j=NULL;
    while(head!=NULL){
        i=head->next;
        head->next=j;
        j=head;
        head=i;
    }
    head=j;
    return head;
}
void print(struct node* head){
    
    if(head==NULL){
        printf("list is empty\n");
    }    
    else{
        struct node* temp=NULL;
        temp=head;
        printf("Your list Data:\n");
        while(temp!=NULL){
            printf(" %d\n",temp->data);
            temp=temp->next;
        
        }
    }
}
int main()
{
    int n,data,pos,p,a,b;
    
    printf("Enter the total number of nodes: ");
    scanf("%d",&n);
    creatlist(n);
    print(head);
    sort(head);
    print(head);
    head=rev(head);
    print(head);
          
    return 0;
}
