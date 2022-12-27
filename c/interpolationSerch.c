#include<stdio.h>
#include<stdlib.h>
int interpolationSerch(int arr[],int Q,int L, int R){
	while(arr[L]!=arr[R] && Q>=arr[L] && Q<=arr[R]){
		int pos=L+((R-L)/(arr[L]-arr[R]))*(Q-arr[L]);
		if(arr[pos]==Q)
		return pos;
		if(arr[pos]<Q)
		L=pos+1;
		else
		R=pos-1;
	}
	return -1;
}

int main(void)
{
	int len,index,Q=10,arr[]={2,3,4,10,40};
	len=sizeof(arr)/sizeof(arr[0]);	
	index=interpolationSerch(arr,Q,0,len-1);
	if (index==-1)
		printf("Number not found");
	else
		printf("Index=%d",index);
	return 0;
}