#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("+ Nhap vao 2 so a, b : ");
    scanf("%d %d",&a,&b);

    int p = a*b;
    printf("=> BCNN(%d, %d) = ",a,b);

    while(b != 0)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }

    printf("%d",p/a);
    return 0;
}
