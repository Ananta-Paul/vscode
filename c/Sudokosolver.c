#include<stdio.h>
#define n 9
void print(int mat[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
int issafe(int mat[n][n],int row ,int col,int num){
    for(int i=0;i<9;i++){
        if(mat[row][i]==num)
        return 0;
    }
    for(int j=0;j<9;j++){
        if(mat[j][col]==num)
        return 0;
    }
    int strow=row-row%3;
    int stcol=col-col%3;
    for(int i=strow;i<strow+3;i++){
        for(int j=stcol;j<stcol+3;j++){
            if(mat[i][j]==num)
            return 0;
        }
    }
    return 1;
}
int sudokosolve(int mat[n][n],int row,int col){
    if(row==n-1 && col==n)
    return 1;
    if(col==n){
        row++;
        col=0;
    }
    if (mat[row][col]>0)
     return sudokosolve(mat,row,col+1);
    for(int i=1;i<=n;i++){
        if(issafe(mat,row,col,i)){
        mat[row][col]=i;
        if(sudokosolve(mat,row,col))
        return 1;
    }
    mat[row][col]=0;
    }
    return 0;
}
void main(){
    int mat[n][n]={ {0,0,0,1,6,0,0,0,5 },
                    { 1,2,0,0,3,5,0,0,0 },
                    { 0,0,6,0,0,0,0,9,0 },
                    { 9,8,2,4,1,0,5,0,7},
                    { 0,0,0,0,0,2,4,0,9 },
                    { 0,1,5,3,7,9,6,0,8 },
                    { 6,9,0,7,0,0,0,5,0},
                    { 0,4,1,0,0,0,0,7,2 },
                    { 0,0,0,0,0,3,0,0,1 } };
    if(sudokosolve(mat,0,0)){
        printf("\nAfter solving ....\n");
        print(mat);}
    else
    printf("No solution exist");
}