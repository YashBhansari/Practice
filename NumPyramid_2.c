#include <stdio.h>
int main()
{
    int row, count = 0;
    printf("Enter the Number of rows you want in the number pyramid\n");
    scanf("%d", &row);
    for (int i = 1; i <= row; i++)
    {
        for (int j = 0; j < row - i; j++)
        {
            printf("\t");
        }
        for (int p = 1; p <= i; p++)
        {
            count++;

            printf("\t%d\t", count);
        }
        printf("\n");
    }
    return 0;
}
