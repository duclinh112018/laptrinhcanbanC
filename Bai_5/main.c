#include <stdio.h>
#include <stdlib.h>

// Đệ quy

/*double giaithua(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return n*giaithua(n-1);
}*/

int main()
{
    int n;
    printf("+ Nhap vao n : ");
    scanf("%d",&n);
    //printf("=> %d! = %.0lf",n,giaithua(n));
    int i;
    double gt = 1.0;
    for (i=1; i<=n; i++)
    {
        gt *= i;
    }
    printf("=> %d! = %.0lf",n,gt);
    return 0;
}
