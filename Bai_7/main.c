#include <stdio.h>
#include <stdlib.h>

int tgv(int a, int b, int c)
{
    if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
        return 1;
    else
        return 0;
}

int main()
{
    int c1,c2,c3;
    printf("+ Nhap vao 3 canh cua tam giac : ");
    scanf("%d %d %d",&c1,&c2,&c3);

    if(c1 > 0 && c2 > 0 && c3 > 0 && c1+c2>c3 && c1+c3>c2 && c2+c3>c1)
    {
        if(c1 == c2 || c2 == c3 || c1 == c3)
        {
            if(c1 == c2 && c2 == c3)
                printf("=> Tam giac deu");
            else if(tgv(c1,c2,c3) == 1 || tgv(c2,c3,c1) == 1 || tgv(c1,c3,c2) == 1)
                printf("=> Tam giac vuong can");
            else
                printf("=> Tam giac can");
        }
        else if(tgv(c1,c2,c3) == 1 || tgv(c1,c3,c2) == 1 || tgv(c2,c3,c1) == 1)
            printf("=> Tam giac vuong");
        else
            printf("=> Tam giac thuong");
    }
    else
        printf("=> Khong phai tam giac");
    return 0;
}
