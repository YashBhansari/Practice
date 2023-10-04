#include <stdio.h>
//to print fibonacci series upto nth element.
int main()
{
    int n, a1 = 0, a2 = 1, x;
    printf("Enter the number of elements (n) you want to print in the fibonacci series -\n");
    scanf("%d", &n);
    if(n==0)
        printf("Enter a valid entry.");
    else if (n == 1)
        printf("0");
    else
    {
        printf("%d %d ", a1, a2);
        for (int i = 3; i <= n; i++)
        {
            x = a1 + a2;
            printf("%d ", x);
            a1 = a2, a2 = x;
        }
    }
    return 0;
}
