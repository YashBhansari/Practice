#include <stdio.h>
float num,a,b,c;
int n,i;
void nvalue()
{
    a=0;
    do
    {
        c=a;
        for (i=1;i<n;i++)
        {
            c=a*c;
            
        }
        a=a+0.000001;
    }
    while (c<=num);
    b=a-0.000002;
    printf("\n\nThe %dth root of your entered number is %f.",n,b);
}
void main()
{
    printf("Enter a number you want to find the nth root of- ");
    scanf("%f",&num);
    printf("Enter the value of n-");
    scanf("%d",&n);
    nvalue();
}
