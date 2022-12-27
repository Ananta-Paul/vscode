#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* head=NULL;
void creatlist(int);
struct node* add( struct node* head, int data,int pos){
    struct node *ptr;
    struct node *ptr2=malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->next=NULL;
    ptr=head;
    if(pos==1){
        ptr2->next=head;
        head=ptr2;
    }
    else{
        pos--;
        while(pos!=1){
            ptr=ptr->next;
            pos--;
        }
        ptr2->next=ptr->next;
        ptr->next=ptr2;
    }
    return head;
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

struct node* delpos(struct node* head,int pos){
    struct node *p;
    struct node *c;
    p=head;
    c=p;
    if (head==NULL){
        printf("List is Empty");
    }
    else if(pos==1){
       head=c->next;
       free(c);
       c=NULL; 
    }
    else{
        while(pos!=1){
            p=c;
            c=c->next; 
            pos--;          
        }
        p->next=c->next;
        free(c);
        c=NULL; 
        printf("%d",c);
    }
    return head; 

}
void delall(){
    struct node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        free(head);
        head=temp;
    }
}
void print(struct node* head){
    
    if(head==NULL){
        printf("list is empty\n");
    }    
    else{
        struct node* temp=NULL;
        temp=head;
        printf("Your list data:\n");
        while(temp!=NULL){
            printf(" %d ",temp->data);
            temp=temp->next;
        
        }
    }
}

int main()
{
    int n,data,pos,p,a,b;
    print(head);
    do{
        printf("\nEnter 1 for add node \nEnter 2 for delete a node\nEnter 3 for delete all\nEnter 4 for sort the list\nEnter 5 for reverse the list\nEnter your choice:");
        scanf("%d",&a);
       
        switch(a){
            case 1:{
                if(head==NULL){
                printf("Enter the total number of nodes: ");
                scanf("%d",&n);
                creatlist(n);
                print(head);
                }
                else{
                printf("Enter the data to add to the list:");
                scanf("%d",&data);
                printf("Enter the position to add: ");
                scanf("%d",&pos);
                head=add(head,data,pos);
                print(head);
                }
                break;
            }
            case 2:{
                printf("\nEnter the position to delete: ");
                scanf("%d",&p);
                head=delpos(head,p);
                printf("Your list after delation: \n");
                print(head);
                break;
            case 3:{
                delall(head);
                printf("Your list after delation: \n");
                print(head);
                break;
            }
            case 4:{
                sort(head);
                print(head);
                break;
            }
            case 5:{
                head=rev(head);
                print(head);
                break;
            }
            default:
            printf("Wrong input\n");
            }}
            printf("\nEnter 1 for repeat operation:");
            scanf("%d",&b);
    }while(b==1);
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


