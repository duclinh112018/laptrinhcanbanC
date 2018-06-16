#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Nhap n : ");
    scanf("%d",&n);
    int i;
    int a[n][n];
    int d=0;
    int run=1;
    int hang = n-1;
    int cot = n-1;

    while(d <= n/2)
    {
        for (i=d; i<=cot; i++)
            a[d][i] = run++;
        for (i=d+1; i<=hang; i++)
            a[i][cot] = run++;
        for (i=cot-1; i>=d; i--)
            a[hang][i] = run++;
        for (i=hang-1; i>d; i--)
            a[i][d] = run++;
        d++; hang--; cot--;
    }
    int j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
