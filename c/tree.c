#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct TREE {
	int data;
	struct TREE *left;
	struct TREE *right;
}TREE;
void inordertraversal(TREE*);
int main() {
	TREE *tree =NULL;
	TREE *temp=NULL;
	TREE *InsertTree(int data,TREE *p);
	TREE *serch(int,TREE*);
	TREE *min(TREE *);
	TREE *delete(TREE *,int);
	TREE *PrintTreeTriangle(TREE*, int);
	int TreeDepth(TREE *tree,int *depth,int level);
    int n,a,b;
    //int array[]={30,15,60,45,75,7,22,17,27,6,8}; 
	int data,depth;
	int array[100];
	do{
        printf("\nEnter 1 for creat tree \nEnter 2 for delete a node\nEnter 3 for serch\nEnter your choice:"); 
        scanf("%d",&a);
        switch(a){
            case 1:{
			printf("Enter the no of element:");
			scanf("%d",&n);
			printf("Enter the tree values top to buttom:");
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);
        for(int i=0;i<n;i++){
            data=array[i];
		if (data==0)
			  break;
		tree =InsertTree(data,tree);
		}
		printf("\n Tree Display after creat:\nIn preoder:\n");
		inordertraversal(tree);
		printf("\nIn triangle shape:\n");
		PrintTreeTriangle(tree,1);
		depth=0;
		TreeDepth(tree,&depth,0);
		printf("\nTree Depth =%d\n",depth);
		break;
        }
		case 3:{
		printf("Enter the data you want to serch: ");
		scanf("%d",&a);
		temp=serch(a,tree);
		if(temp)
		printf("Found!");
		else
		printf("\nData not found\n");
		break;
		}
		case 2:{
		if(tree==NULL)
		printf("Create tree first!\n");
		else{
		printf("Enter the data you want to delete: ");
		scanf("%d",&a);
		delete(tree,a);
		printf("\n Tree Display after delete:\nIn preoder:\n");
		inordertraversal(tree);
		printf("\nIn triangle shape:\n");
		PrintTreeTriangle(tree,1);
		depth=0;
		TreeDepth(tree,&depth,0);
		printf("\nTree Depth =%d\n",depth);
		}
		break;
		}}
		printf("\nEnter 1 for repeat operation:");
            scanf("%d",&b);
    }while(b==1);
		
	return(0);
}
TREE *InsertTree(int data,TREE *p) {
	if(!p) {
		p=(TREE*)malloc(sizeof(TREE));
		p->data=data;
		p->left=NULL;
		p->right=NULL;
		return(p);
	}
	if(data < p->data)
		p->left=InsertTree(data,p->left); 
    else if(data > p->data)
		p->right=InsertTree(data,p->right);
	return(p);
}
TREE* serch(int a,TREE*p){
	if(p==NULL)
    return NULL;
	else if(a>p->data){
		p=p->right;
		serch(a,p);
	}
	else if(a<p->data){
		p=p->left;
		serch(a,p);
	}
	else{
		return p;
	}
}
TREE *min(TREE *tree){
	while(tree->left!=NULL){
		tree=tree->left;
	}
	return tree;
}
void inordertraversal(TREE *root){
   if (root != NULL){
      inordertraversal(root->right);
      printf("%d ", root->data);
      inordertraversal(root->left);
   }
}
TREE *PrintTreeTriangle(TREE *tree, int level) {
	int i;
	if(tree) {
		PrintTreeTriangle(tree->right,level+1);
		printf("\n");
		for (i=0;i<level;i++)
				printf("    ");
		printf("%d",tree->data);
		PrintTreeTriangle(tree->left,level+1);
	}
	return(NULL);
}
TREE* delete(TREE* root, int data)
{
if (root == NULL)
return root;
// If the key to be deleted is smaller than the root's key,
if (data < root->data)
root->left = delete(root->left, data);
// If the key to be deleted is greater than the root's key,
else if (data > root->data)
root->right = delete(root->right, data);
else
{
// node with only one child or no child
if (root->left == NULL)
{
TREE *temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL)
{
TREE *temp = root->left;
free(root);
return temp;
}
// node with two children:
TREE* temp = min(root->right);
// Copy the inorder successor's content to this node
root->data = temp->data;
// Delete the inorder successor
root->right = delete(root->right, temp->data);
}
return root;
}
// TREE *delete(TREE *t,int d){
// 	TREE *temp=NULL;
// 	if(t==NULL)
//     return NULL;
// 	else if(d>t->data)
// 		return delete(t->right,d);
// 	else if(d<t->data)
// 		return delete(t->left,d);
// 	else{
// 	if(t->right && t->left){
// 		temp=min(t->right);
// 		t->data=temp->data;
// 		return delete(t->right,t->data);
// 	}
// 	else{
// 		temp=t;	
// 	if(t->left==NULL&& t->right==NULL){
// 	free(t);
// 	return NULL;}
// 	if(t->left==NULL)
// 		t=t->right;
// 	else if(t->right==NULL)
// 		t=t->left;
// 		free(temp);
// 		return temp;
// 	}
// 	return t;
// }
// }
int TreeDepth(TREE *tree,int *depth,int level) {
	if(tree) {
		if (level>*depth)
		     *depth=level;
		TreeDepth(tree->left,depth,level+1);
		TreeDepth(tree->right,depth,level+1);
	}
	return(0);
}