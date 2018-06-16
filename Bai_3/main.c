#include <stdio.h>
#include <stdlib.h>

void show(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%4d",arr[i]);
    }
}

int main()
{
    int n,i,j;
    printf("+ Nhap vao so luong phan tu n : ");
    scanf("%d",&n);
    int a[n];
    for (i=0; i<n; i++)
    {
        printf("+ a[%d] = ",i);
        scanf("%d",&a[i]);
    }

    printf("=> Day so vua nhap : ");
    show(a,n);

    printf("\n=> Day so sau khi sap xep tang dan : ");
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    show(a,n);
    return 0;
}
