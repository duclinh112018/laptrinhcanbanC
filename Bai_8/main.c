#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,i;
    printf("+ Nhap vao so phan tu cua day : ");
    scanf("%d",&n);

    int a[n];
    for (i=0; i<n; i++)
    {
       printf("+ a[%d] = ",i);
       scanf("%d",&a[i]);
    }

    printf("=> Day sau khi nhap : ");
    for (i=0; i<n; i++)
    {
        printf("%4d",a[i]);
    }

    int max = a[0];
    int min = a[0];

    int vt_min = 0, vt_max = 0;

    for (i=0; i<n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
            vt_max = i;
        }
        if(a[i] < min)
        {
            min = a[i];
            vt_min = i;
        }
    }
    printf("\n=> Max  = %d, vi tri : %d\n",max,vt_max);
    printf("=> Min = %d, vi tri min: %d",min, vt_min);
    return 0;
}
