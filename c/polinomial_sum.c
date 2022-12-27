#include<stdio.h>
#include<stdlib.h>
struct node{
    float cof;
    int exp;
    struct node *next;
};
struct node* in(struct node* head,float c,int x){
    struct node* temp;
    struct node *newp=malloc(sizeof(struct node));
    newp->cof=c;
    newp->exp=x;
    newp->next=NULL;
    if(head==NULL||x>head->exp){
        newp->next=head;
        head=newp;
    }
    else{
        temp=head;
        while(temp->next!=NULL && temp->next->exp>=x)
            temp=temp->next;
            newp->next=temp->next;
            temp->next=newp;        
        return head;
    }
}
    
struct node* create(struct node* head){
    int n,i,ex;
    float co;
    printf("Enter the number of term: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the coefficient for term %d: ",i+1);
        scanf("%f",&co);
        printf("Enter the exponent for term %d: ",i+1);
        scanf("%d",&ex);
        head=in(head,co,ex); 
    }
    return head;
}
void print(struct node* head){
    
    if(head==NULL){
        printf("Nothing found\n");
    }    
    else{
        struct node* temp=NULL;
        temp=head;
        printf("Polynomial:\n");
        while(temp!=NULL){            
            printf("(%.1fX^%d) ",temp->cof,temp->exp);
            temp=temp->next;
            if(temp!=NULL){
                printf("+");
            }
            else
            printf("\n");    
        }
    }
}
struct node* sim(struct node* head3){
struct node* ptr3=head3;
    struct node* temp=NULL;
    while(ptr3->next!=NULL){
        if((ptr3->cof==0&& ptr3==head3) || ptr3->next->cof==0 ){
            if(ptr3->cof==0 && ptr3==head3){            
                    head3=temp;
                    head3=head3->next;
                    free(temp);
                }
            else if(ptr3->next->cof==0){
                temp=ptr3->next;
                ptr3->next=ptr3->next->next;
                free(temp);
            }
        }
        else if(ptr3->exp==ptr3->next->exp){
            ptr3->cof=ptr3->cof+ptr3->next->cof;
            temp=ptr3->next;
            ptr3->next=ptr3->next->next;
            free(temp);
        }
        
        else{
        ptr3=ptr3->next;
        }
    }
    print(head3);
}
void sumpoly(struct node* head1,struct node*head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while(ptr1!=NULL&& ptr2!=NULL){
        if (ptr1->exp==ptr2->exp){
            head3=in(head3,ptr1->cof+ptr2->cof,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->exp>ptr2->exp){
            head3=in(head3,ptr1->cof,ptr1->exp);
            ptr1=ptr1->next;
        }
        else if(ptr1->exp<ptr2->exp){
            head3=in(head3,ptr2->cof,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
        while(ptr1!=NULL){
            head3=in(head3,ptr1->cof,ptr1->exp);
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL){
            head3=in(head3,ptr1->cof,ptr1->exp);
            ptr1=ptr1->next;
        }
        printf("After adding the two entered polynomial:\n");
        print(head3);
        printf("After simplyfication:\n");
        sim(head3);
}
void multpoly(struct node* head1,struct node* head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            head3=in(head3,ptr1->cof*ptr2->cof,ptr1->exp+ptr2->exp);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
        ptr2=head2;
    }
    printf("After multiplication of above two plynomials:\n");
    print(head3);
    printf("After simplyfication:\n");
    sim(head3);
}


int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    struct node* head3=NULL;
    int n,pos,p,pow,a,b;
    float data;
            printf("Enter one polynomial:\n");
            head1=create(head1);
            print(head1);
            printf("Enter second polynomial:\n");
            head2=create(head2);
            print(head2);
            do{
            printf("For sumation press 1\nFor multiplication press 2\nEnter your choice: ");
            scanf("%d",&n);
            switch(n){
                case 1:{
                sumpoly(head1,head2);
                break;
                }
                case 2:{           
                multpoly(head1,head2);
                break;
                }
                default:
                printf("Wrong input! Sorry");
            }
            printf("\nEnter 1 for repeat operation:");
            scanf("%d",&b);
    }while(b==1);
    return 0;
}