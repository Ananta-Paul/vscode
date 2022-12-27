#include<stdio.h>
void quicksort(int arr[10],int f,int l ){
    int pivot,i,j,temp,a;
    if (l>f)
    {   a=f;
        pivot=arr[l];
        i=f;
        j=l;
        while (i<j)
        {
            while (arr[i]<=arr[a] && i<l)
            {
                i++;
            }
            while (arr[j]>arr[a])
            {
                j--;
            }
            if (i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            } 
        }
        temp=arr[a];
        arr[a]=arr[j];
        arr[j]=temp;

        quicksort(arr,f,j-1);
        quicksort(arr,j+1,l);
    }
    
}

int main(){
    int i,n;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int arr[n];
    for ( i = 0; i < n; i++){
        printf("Enter %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Sorted elements: ");
    for ( i = 0; i <n; i++)
    printf(" %d -",arr[i]);
    printf("/");   
    return 0;
}