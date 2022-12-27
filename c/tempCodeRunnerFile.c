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
struct node* add(struct node* head){
    int p,i,c=0,data;
    if(head==NULL){
        head=creatlist(head);
        return head;
    }
    else{
    printf("Enter the position you want to add: ");
    scanf("%d",&p);
    printf("Enter the data you want to add: ");
    scanf("%d",&data);
    struct node *t;
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    for(t=head;t!=NULL;t=t->next)
        c++;
        //printf("%d\n",c);
    if(p==1){
        temp->next=head;
        head=temp;
        return head;
    }
    else if(p==c+1)
        addtoend(head,data);
    else if(p<=c && p>1){
        struct node *ptr;
        ptr=head;
        for(i=1;i<p;i++){
            ptr=ptr->next;
        }
        ptr->prev->next=temp;
        temp->prev=ptr->prev;
        ptr->prev=temp;
        temp->next=ptr;    
    }
    else
    printf("add is not posible\n");
    return head;
}
}
struct node* delpos(struct node* head){
    if(head==NULL){
        printf("Delete is not posible because list is already empty\n");
    return head;
    }
    else{
    int p,i,a,c=0;
    struct node* temp,*ptr,*t;
    printf("Enter 1 for delete the total linked list\nEnter 2 for delete at a position:");
    scanf("%d",&a);
    if(a==1){
        ptr=head;
        while(head!=NULL){
            head=head->next;
            free(ptr);
            ptr=head;
        }
        return head;
    }
    else if(a==2){
    printf("Enter the position you want to delete: ");
    scanf("%d",&p);
     for(t=head;t!=NULL;t=t->next)
        c++;
        //printf("%d\n",c);
    ptr=head;
    if(p==1){
        head=ptr->next;
        ptr->next->prev=NULL;
        free(ptr);
        return head;
    }
    else if(p==c){
        for(i=1;i<p-1;i++){
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=NULL;
        free(temp);
        return head;
    }
    else if(p<c && p>1){
        for(i=1;i<p;i++){
            ptr=ptr->next;
        }
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);    
    }
    else
    printf("Delete is not posible\n");
    return head;
    }
    else
    printf("wrong input\n");
    }
}
void sort(struct node* head){
     if(head==NULL){
        printf("Sorting is not posible because list is empty\n");
    }
    else{
        int temp;
        struct node *i,*j;
        for (i=head;i->next!=NULL;i=i->next){
            for(j=i->next;j!=NULL;j=j->next){
                if (i->data>j->data){
                    temp=j->data;
                    j->data=i->data;
                    i->data=temp;
                }
            }
        }
}
}
struct node* rev(struct node* head){
    if(head==NULL){
        printf("Reverse is not posible because list is empty\n");
    return head;
    }
    else{
    struct node* ptr=head;
    struct node* temp=head->next;
    ptr->next=NULL;
    ptr->prev=temp;
    while(temp!=NULL){
        temp->prev=temp->next;
        temp->next=ptr;
        ptr=temp;
        temp=temp->prev;
    }
    head=ptr;
    return head;
    }
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
    int a,b;
    do{
    printf("Enter 1 for add node\nEnter 2 for delete node\nEnter 3 for sort the nodes\nEnter 4 for reverse\nEnter your choice:");
    scanf("%d",&a); 
    switch(a){
        case 1:{
        head=add(head);
        print(head);
        break;
        }
        case 2:{
            head=delpos(head);
            print(head);
            break;
        }
        case 3:{
            sort(head);
            print(head);
            break;
        }
        case 4:{
            head=rev(head);
            print(head);
            break;
        }
        default:
        printf("Sorry! wrong input\n");
    }
    printf("Enter 1 to repeat any operation:");
    scanf("%d",&b);
    }while(b==1);   
    return 0;
}