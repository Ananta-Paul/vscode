#include <stdio.h>
 int count=0;
void towers(int, char, char, char);
 
int main()
{
    int num;
 
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    printf("\n Total no of operations=%d",count);
    return 0;
}
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from %c to %c", frompeg, topeg);
        count++;
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n Move disk %d from %c to %c", num, frompeg, topeg);
    count++;
    towers(num - 1, auxpeg, topeg, frompeg);
}