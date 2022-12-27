#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[20];
    int age;
    int speed;
    char caste[2];
    int sel;
    struct node *next;
};
struct node* head=NULL;
void creatlist(int);
void print(struct node* head){
    
    if(head==NULL){
        printf("list is empty\n");
    }    
    else{
        struct node* temp=NULL;
        temp=head;
        printf("\nParticipant list:\nCandidate no\t  Name\t\t Age \t Running speed\t Caste \n");
        for(int i=1;temp!=NULL;i++,temp=temp->next){
            printf(" %d \t\t%s \t %d\t\t%d \t  %s\n",i,temp->name,temp->age,temp->speed,temp->caste);
        }
        temp=head;
        printf("\nSelected candidate list:\nCandidate no\t  Name\t\t Age \t Running speed\t Caste \n");
        for(int i=1;temp!=NULL;i++,temp=temp->next){
		if(((temp->caste[0]=='g'|| temp->caste[0]=='G')&& temp->speed>=12 && temp->age>=18 && temp->age<=25)||((temp->caste[0]=='s'|| temp->caste[0]=='S'|| temp->caste[0]=='O' || temp->caste[0]=='o')&& temp->speed>=10 && temp->age>=18 && temp->age<=30))
		{
				temp->sel=1;
				printf(" %d \t\t%s \t %d\t\t%d \t  %s\n",i,temp->name,temp->age,temp->speed,temp->caste);
		}
	}
	printf("\nList of non_selected candidates");
    printf("\nCandidate no\t  Name\t\t Age \t Running speed\t Caste \n");
	temp=head;
    for(int i=1;temp!=NULL;i++,temp=temp->next){
		if(temp->sel!=1)
		{	
		printf(" %d \t\t%s \t %d\t\t%d \t  %s\n",i,temp->name,temp->age,temp->speed,temp->caste);
        }	
    }
}
}

int main()
{
    int n,data,pos,p,a,b;
                printf("Enter the total number of candidates: ");
                scanf("%d",&n);
                creatlist(n);
                print(head);
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
        printf("Enter the data of candidate 1:\n");
        printf("Name:");
        scanf("%s", head->name);
        printf("Age:");
        scanf("%d",&head->age);
        printf("Running speed:");
        scanf("%d",&head->speed);
        printf("Caste(General/SC/ST/OBC):");
        scanf("%s",&head->caste);
        head->sel=0;
        head->next=NULL;
        temp=head;

        for(i=2;i<=n;i++){
            newnode=(struct node*)malloc(sizeof(struct node));
            if (newnode==NULL){
                printf("\nempty");
                break;
            }
            else{
                printf("\nEnter the data of candidate %d:\n",i);
                printf("Name:");
                scanf("%s", newnode->name);
                printf("Age:");
                scanf("%d",&newnode->age);
                printf("Running speed:");
                scanf("%d",&newnode->speed);
                printf("Caste(General/SC/ST/OBC):");
                scanf("%s",&newnode->caste);
                head->sel=0;
                newnode->next=NULL;
                temp->next=newnode;
                temp=temp->next;                    
            }
        }
        printf("\nlist created successfully\n");
    }
}