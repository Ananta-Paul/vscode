#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == ')')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}
void reverse(char exp[]){
    char temp[100];
    int i,j;
    for(i=strlen(exp)-1,j=0;i+1!=0;--i,++j)
        temp[j]=exp[i];
    temp[j]='\0';
    strcpy(exp,temp);
    

}
void print(char temp[]){
    int i=0;
    while(temp[i]!='\0'){
    printf("%c",temp[i]);
    i++;
    }
    printf("\n");
}
void intopost(char exp[]){
    char *e,x;
    e = exp;
     while(*e != '\0')
    {
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '('){
                printf("%c", x);
            }
        }
        else
        {
        while(priority(stack[top]) >= priority(*e)){
                printf("%c",pop());
        }
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }

}

void intopre(char exp[]){
    char *e,x;
    e = exp;
    int i=0;
    char temp[100];
    
    while(*e != '\0')
    {
        if(isalnum(*e)){
            //printf("%c ",*e);x^y/(5*z)+2
            temp[i]=*e;
            i++;
        }
        else if(*e == ')')
            push(*e);
        else if(*e == '(')
        {
            while((x = pop()) != ')'){
                //printf("%c ", x);
                temp[i]=x;
                i++;
            }
        }
        else
        {
        while(priority(stack[top]) >= priority(*e)){
                //printf("%c ",pop());
                temp[i]=pop();
                i++;
        }
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        //printf("%c ",pop());
        temp[i]=pop();
        i++;
    }
    temp[i]='\0';
    //printf("%d\n%d\n",e,i);
    //temp[i]=exp[i];
    reverse(temp);
    
    print(temp);
}

int main()
{
    char exp[100];
    int a,b;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    printf("Enter 1 for postfix\nEnetr 2 for prefix\nEnter yourchoice: ");
    scanf("%d",&a);
    switch(a){
        case 2:{
            reverse(exp);
            intopre(exp);   
            break;
        }
        case 1:{
            intopost(exp);
            break;
        }
        default:
        printf("Wrong input");
    }
    return 0;
}