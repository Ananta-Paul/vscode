#include <stdio.h>
int print(int i){
    char n[]="ANANTA";
    //int i=0;
    if (n[i]=='\0'){
    i=0;
    }
    printf("%c",n[i]);
    i+=1;
    return i;
}  
void main(){
    int p=0;
    int r,c,i,j,n=15;
    for(r=0;r<n;r++){
    for(c=0;c<2*n+5;c++){
        if(r<=n/3){
            if((r==n/3 && c!=((2*n+4)/2))||(r==((n/3)-1) && c!=n+1 &&c!=n+2&&c!=n+3 ))
            printf("*");
            else if(r<=((n/3)+n%10) && r>n/3)
            printf("*");
            else
            printf(" ");
        }
      }
      printf("\n");
    }
}                                                                                 
    //      aaa             aaa
    //   aaaaaaaaa       aaaaaaaaa
    // aaaaaaaaaaaaa   aaaaaaaaaaaaa
    // aaaaaaaaaaaaaa aaaaaaaaaaaaaa
    // aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    //  aaaaaaaaaaaaaaaaaaaaaaaaaaa
    //    aaaaaaaaaaaaaaaaaaaaaaa
    //     aaaaaaaaaaaaaaaaaaaaa
    //       aaaaaaaaaaaaaaaaa
    //         aaaaaaaaaaaaa
    //            aaaaaaa
    //             aaaaa
    //               a
    //          
