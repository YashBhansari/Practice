#include <stdio.h>
//To print factors of a given number
int main()
{
    int n,f[64],a=0;
    printf("Enter a number to check if it is a perfect number or not - \n");
    scanf("%d",&n);

    for (int i=1; i<=n; i++)
    {
        if (n % i == 0)
        {
            f[a]=i;
            a++;
        }
    }
    int c=0;
    for (int i=a; i<a; i++)
    {
        c=c+f[i];
    }
    if (c == n)
    printf("Entered number is a perfect number.");
    else 
    printf("Entered number isn't a perfect number.");
}
