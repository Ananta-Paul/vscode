#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[30];
	int age;
	int running_time;
	char caste_attributes;
	char selected;
	struct node *next;

}*head,*temp;
void createlist(int a)
{
	struct node *nnode;
	nnode=(struct node*)malloc(sizeof(struct node));
	if(nnode==NULL)
	{
		printf("MEMORY ALOCATION FAILED");
		exit(0);
	}
	fflush(stdin);
	printf("Enter the name of participant %d\t",a);
	gets(nnode->name);
	printf("Enter the age of participant %d\t",a);
	scanf("%d",&nnode->age);
	printf("Enter the running speed of participant %d(in km/hr)\t",a);
	scanf("%d",&nnode->running_time);
	fflush(stdin); 
	printf("Enter the caste attributes of participant %d(General/SC/ST/OBC)\t",a);
	scanf("%c",&nnode->caste_attributes);
	
	temp->next=nnode;
	temp=nnode;
	temp->next=NULL;
}
void printlist()
{
	temp=head;int i;
	printf("List of selected candidates\n");
	while(temp!=NULL)
	{
		if(temp->caste_attributes=='G'|| temp->caste_attributes=='g')
		{
			if(temp->running_time>=12)
			{
				if(temp->age>=18 && temp->age<=25)
				{
					
				temp->selected='y';
				printf("The name of candidate %s\n",temp->name);
				printf("The age of candidate %d\n",temp->age);
				printf("The running speed of candidate %d\n",temp->running_time);
				printf("The caste attributes of candidate %c\n",temp->caste_attributes);
				
			    }
			
			}
			
		}
		else if(temp->caste_attributes=='s'|| temp->caste_attributes=='S'|| temp->caste_attributes=='O'|| temp->caste_attributes=='o')
		{
			if(temp->running_time>=10)
			{
				if(temp->age>=18 && temp->age<=30)
				{
				temp->selected='y';
				printf("The name of candidate %s\n",temp->name);
				printf("The age of candidate %d\n",temp->age);
				printf("The running speed of candidate %d\n",temp->running_time);
				printf("The caste attributes of candidate %c\n",temp->caste_attributes);
			    }
			}
		}
		temp=temp->next;
		printf("\n");
	}
	printf("List of non_selected candidates\n");
	temp=head;
	while(temp!=NULL)
	{
		if(temp->selected!='y')
		{
			
		puts(temp->name);
		printf("The age of candidate %d\n",temp->age);
		printf("The running speed of candidate %d\n",temp->running_time);
		printf("The caste attributes of candidate %c\n",temp->caste_attributes);
			
		}
		temp=temp->next;
		printf("\n");
	}
}
int main()
{ int i;int n;
printf("Enter the number of candidates\t");
scanf("%d",&n);
	head=(struct node*)malloc(sizeof(struct node));
		if(head==NULL)
	{
		printf("MEMORY ALOCATION FAILED");
		exit(0);
	}
	fflush(stdin);
	printf("Enter the name of participant 1\t");
	gets(head->name);

	printf("Enter the age of participant 1\t");
	scanf("%d",&head->age);
	printf("Enter the running speed of participant 1(in km/hr)\t");
	scanf("%d",&head->running_time);
	fflush(stdin);
	printf("Enter the caste attributes of participant 1(G-for general/S-SC/ST/O-OBC)\t");
	scanf("%c",&head->caste_attributes);
	head->next=NULL;
	temp=head;
	for(i=2;i<=n;i++)
	{
		createlist(i);
	}
	printlist();
	return 0;
}