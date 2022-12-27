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
   
int main() {  
    int i,j, rows;
    int p=0;
    printf("Enter the number of rows\n");
    scanf("%d", &rows);  
    /* printing top semi circular shapes of heart */
    for(i = (rows/2); i <= rows; i+=2){ 
     /* Printing Spaces */
        for(j = 1; j < rows-i; j+=2) {  
            printf(" ");  
        }
        /* printing stars for left semi circle */
        for(j = 1; j <= i; j++){  
            p=print(p);  
        }  
        /* Printing Spaces */
        for(j = 1; j <= rows-i; j++){  
            printf(" ");  
        }  
        /* printing stars for right semi circle */
        p=0;
        for(j = 1; j <= i; j++){  
            p=print(p);  
        }  
        /* move to next row */
        printf("\n");  
    }  
     
    /* printing inverted start pyramid */
    p=0;
    for(i = rows; i >= -1; i-=2){  
        for(j = i; j < rows; j++){  
            printf(" ");  
        }  
        for(j = 1; j <= (i*2)-1; j++){  
             p=print(p);  
        }  
        /* move to next row */
        printf("\n");  
    }
    // if(rows%2==0){
    //     for(i=rows;)
    //}

    
    
    //   
    //   aaaaa       aaaaa
    // aaaaaaaaa   aaaaaaaaa
    // aaaaaaaaaa aaaaaaaaaa
    //  aaaaaaaaaaaaaaaaaaa
    //   aaaaaaaaaaaaaaaaa
    //     aaaaaaaaaaaaa
    //       aaaaaaaaa
    //         aaaaa
    //           a


    //                   
    //   aaaaaaa       aaaaaaa
    // aaaaaaaaaaa   aaaaaaaaaaa
    // aaaaaaaaaaaa aaaaaaaaaaaa
    //  aaaaaaaaaaaaaaaaaaaaaaa
    //   aaaaaaaaaaaaaaaaaaaaa
    //     aaaaaaaaaaaaaaaaa
    //       aaaaaaaaaaaaa
    //         aaaaaaaaa
    //           aaaaa
    //             a
     // 

     //     aaa             aaa
    //   aaaaaaaaa       aaaaaaaaa
    // aaaaaaaaaaaaa   aaaaaaaaaaaaa
    // aaaaaaaaaaaaaa aaaaaaaaaaaaaa
    //  aaaaaaaaaaaaaaaaaaaaaaaaaaa
    //   aaaaaaaaaaaaaaaaaaaaaaaaa
    //     aaaaaaaaaaaaaaaaaaaaa
    //       aaaaaaaaaaaaaaaaa
    //         aaaaaaaaaaaaa
    //           aaaaaaaaa
    //             aaaaa
    //               a
    //          


    //      aaaaaaa             aaaaaa
    //   aaaaaaaaaaaaa       aaaaaaaaaaaa
    // aaaaaaaaaaaaaaaaa   aaaaaaaaaaaaaaaa
    // aaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaa
    //  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    //   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    //     aaaaaaaaaaaaaaaaaaaaaaaaaaaa
    //       aaaaaaaaaaaaaaaaaaaaaaaa
    //         aaaaaaaaaaaaaaaaaaaa
    //           aaaaaaaaaaaaaaaa
    //             aaaaaaaaaaaa
    //               aaaaaaaa
    //                 aaaa
   //                    a
    return 0;  
}