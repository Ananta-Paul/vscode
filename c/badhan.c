
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node*next;
};
struct node* addtoempty(struct node*head,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

void addtoend(struct node* head,int data){
    struct node* t;
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp;
    temp->prev=t;
}
struct node* creatlist(struct node* head){
    int n,data;
    printf("Enter total num of node:");
    scanf("%d",&n);
    if(n==0){
        return head;
    }
    printf("Enter the data for node 1: ");
    scanf("%d",&data);
    head=addtoempty(head,data);
    for(int i=1;i<n;i++){
        printf("Enter the data for node %d: ",i+1);
        scanf("%d",&data);
        addtoend(head,data);
    }
    return head;
}
struct node* addtobeg(struct node* head){
    int p,i,c=0,data;
    printf("Enter the data you want to insert at beginning: ");
    scanf("%d",&data);
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
        temp->next=head;
        head=temp;
        return head;
    
}
void print(struct node* head){
    struct node* ptr=head;
    if(head==NULL)
    printf("List is Empty\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    struct node* head=NULL;
        head=creatlist(head);
        head=addtobeg(head);
        printf("Displaying nodes....\n");
        print(head);
    return 0;
}