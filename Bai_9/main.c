#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, i, j;
    printf("+ Nhap vao so hang, cot : ");
    scanf("%d %d",&row, &col);

    int a[row][col];

    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            printf("+ a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    int max = a[0][0];
    int min = a[0][0];

    printf("=> Ma tran sau khi nhap : \n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            if(a[i][j] > max)
                max = a[i][j];
            if(a[i][j] < min)
                min = a[i][j];
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n=> Max = %d",max);
    printf("\n=> Min = %d",min);
    return 0;
}
