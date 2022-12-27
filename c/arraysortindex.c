#include<stdio.h>
void sort(int number[10],int n,int arr[10] ){
    int i,j,temp,a;
    for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (number[i] > number[j]) 
                {
 
                    a =  number[i];
                    number[i] = number[j];
                    number[j] = a;
                    temp =  arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
 
                }
 
            }
    
}
}

int main(){
    int i,n;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++){
        printf("Enter %d element of arr[]: ",i+1);
        scanf("%d",&arr[i]);
    }
    int index[n];
    for ( i = 0; i < n; i++){
        printf("Enter %d element of index[]: ",i+1);
        scanf("%d",&index[i]);
    }
    sort(index,n,arr);
    printf("resultant arr[]=");
    for ( i = 0; i <n; i++)
    printf(" %d -",arr[i]);
    printf("|");   
     printf("\nresultant index[]=");
    for ( i = 0; i <n; i++)
    printf(" %d -",index[i]);
    printf("|"); 
    return 0;
}