#include <stdio.h>

int main()
{
    int A;               // a[10] ada 10 array
    char U[100], N[100]; // tian limit
    scanf("%[^\n]", &N);
    scanf("%d %s", &A, &U);

    printf("Name: %s\n", N);
    printf("NIS: %d\n", A);
    printf("Age: %s\n", U);

    return 0;
}