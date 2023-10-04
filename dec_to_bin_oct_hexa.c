#include <stdio.h> // to covert entered decimal value to binary, octal and hexadecimal form
//method 2

void main()
{
    int n;
    int rem2[100], rem8[100], rem16[100];
    printf("Enter a number: ");
    scanf("%d", &n);
   
    int m=n;        //binary
    int count2=0;
    for (int i=0; m>0; i++)
    {
        rem2[i]=m%2;
        m=m/2;
        count2++;
    }
   
    m=n;            //octal
    int count8=0;
    for (int i=0; m>0; i++)
    {
        rem8[i]=m%8;
        m=m/8;
        count8++;
    }
   
    m=n;
    int count16=0;
    int x;
    for (int i=0; m>0; i++)
    {
        x=m%16;
        if (x<10)
            rem16[i] = x;
        else
            rem16[i] = x - 10 + 'A';
        m=m/16;
        count16++;
    }
   
   
    printf("\nBinary: ");
    for (int i=count2-1; i>=0; i--)
        printf("%d",rem2[i]);
    printf("\nOctal: ");
    for (int i=count8-1; i>=0; i--)
        printf("%d",rem8[i]);
    printf("\nHexadecimal: ");
    for (int i=count16-1; i>=0; i--)
    {
        if (rem16[i]<10)
            printf("%d",rem16[i]);
        else
            printf("%c",rem16[i]);
    }
}
