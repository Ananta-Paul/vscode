#include <stdio.h>
struct student {
    char firstName[50];
    int roll;
    int class;
    char section[1];
} s[5];

int main() {
    int i,n;
    printf("Enter information of students:\n");
    printf("Enter the num of student : ");
    scanf("%d",&n);
    // storing information
    for (i = 0; i < n; ++i) {
      
        printf("\nFor %d no student,\n", i+1);
        printf("Enter first name: ");
        scanf("%s", s[i].firstName);
        printf("Enter roll: ");
        scanf("%d", &s[i].roll);
        printf("Enter class: ");
        scanf("%d", &s[i].class);
        printf("Enter section: ");
        scanf("%s", s[i].section);
    }
    printf("\nDisplaying Information:\n\n");

    // displaying information
    for (i = 0; i < n; ++i) {
        printf("For %d no student,\n", i+1);

        printf("\nRoll number: %d\n",s[i].roll);
        printf("Name: ");
        puts(s[i].firstName);
        printf("class: %d", s[i].class);
        printf("\nSection: ");
        puts(s[i].section);
        printf("\n");
    }
    return 0;
}