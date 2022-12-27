#include<stdio.h>
#include<stdlib.h>
int binsrch(int arr[],int Q,int L, int R)
{
	int mid;
	if(R>=L)
	{
		mid=L+(R-L)/2;
		if (arr[mid]==Q)
			return mid;
		if (arr[mid]>Q)
			return binsrch(arr,Q,L,mid-1);
		return binsrch(arr,Q,mid+1,R);
	}
	return -1;
}

int main(void)
{
	int len,index,Q=10,arr[]={2,3,4,10,40};
	len=sizeof(arr)/sizeof(arr[0]);	
	index=binsrch(arr,Q,0,len-1);
	if (index==-1)
		printf("Number not found");
	else
		printf("Index=%d",index);
	return 0;
}