#include<stdio.h>
#include<math.h>
int board[20],c;
int main(){
    int n,i,j;
    void queen( int row,int n);
    printf("enter the number of queen: ");
    scanf("%d",&n);
    queen(1,n);
    return 0;
}
int place(int row, int column){
    int i,j;
    for(i=1;i<=row-1;i++){
        if(board[i]==column)
        return 0;
        if(fabs(board[i]-column)==fabs(row-i))
        return 0;
    }
    return 1;
}
void print(int n){
    int i,j;
    printf("\n\nsolution no %d\n",++c);
    for(i=1;i<n+1;++i)
    printf("\t%d",i);
    for(i=1;i<=n;++i){
        printf("\n\n\n%d",i);
        for(j=1;j<=n;++j){
            if(board[i]==j)
            printf("      |*|");
            else
            printf("\t_");
        }
    }

}
void queen(int row,int n){
    int column;
    for(column=1;column<=n;column++){
        if(place(row,column)){
            board[row]=column;
            if(row==n)
            print(n);
            else
            queen(row+1,n);
        }
    }
}