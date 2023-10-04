#include <stdio.h> // to find binary and octal equivalents of entered decimal digits

void main()
{
    int n;
   
    printf("Enter an integer: ");
    scanf("%d",&n);
   
    int i=n, b=0, x=1;
    while (i>0)
    {
        b = b+ (i%2) * x;
        x = x* 10;
        i = i/2;
    }
   
    i=n,x=1;
    int o=0;
    while (n>0)
    {
        o = o+ (n%8) * x;
        x = x* 10;
        n = n/8;
    }
    printf("\nBinary: %d",b);
    printf("\nOctal: %d",o);
}
