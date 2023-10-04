#include <stdio.h>
int main()
{
    int row, count = 1;
    printf("Enter the Number of rows you want in the number pyramid\n");
    scanf("%d", &row);
    for (int i = 1; i <= row; i++)
    {
        for (int j = 0; j < row - i; j++)
        {
            printf("\t");
        }
        for (int j = 1; j <= count; j++)
        {
            printf("\t%d\t", j);
        }
        printf("\n");
        count++;
    }
    return 0;
}
