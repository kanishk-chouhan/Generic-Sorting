#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sort.h>

typedef struct __student
{
    int roll_number;
    char name[26];
} Student;
int myComparator(void *left, void *right)
{
    Student *a, *b;
    a = (Student *)left;
    b = (Student *)right;
    return stricmp(a->name, b->name);
}
int main()
{
    int req, y, rr;
    char n[27];
    Student *x;
    printf("Enter your requirement: ");
    scanf("%d", &req);
    if (req < 0)
    {
        printf("Invalid requirement\n");
        return 0;
    }
    x = (Student *)malloc(sizeof(Student) * req);
    for (y = 0; y < req; y++)
    {
        printf("Enter roll number: ");
        scanf("%d", &rr);
        fflush(stdin);
        x[y].roll_number = rr;
        printf("Enter name: ");
        fgets(n, 27, stdin);
        n[strlen(n) - 1] = '\0';
        strcpy(x[y].name, n);
    }
    binaryInsertionSort(x, req, sizeof(Student), myComparator);
    for (y = 0; y < req; y++)
    {
        printf("%d\t%s\n", x[y].roll_number, x[y].name);
    }
    free(x);
    return 0;
}