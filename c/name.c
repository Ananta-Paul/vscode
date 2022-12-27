#include<stdio.h>
#include<string.h>
void main(){
    int i,j,k,l,m,n,r,c;
    for(r=0;r<5;r++){
        for(i=0;i<6;i++){
            for(c=0;c<9;c++){
                if(((i==0||i==2||i==5)&&(r+c==4||c-r==4||(r==3&&c<8&&c>1&&c%2!=0)))||((i==1||i==3)&&(c==0||c==8||(c==r*2)))||(i==4&&(r==0||c==4)&&(c%2==0)))
                printf("*");
            else
            printf(" ");   }
        printf("  ");}
printf("\n");}}