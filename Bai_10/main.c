#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, y;
    printf("+ Nhap vao thang , nam : ");
    scanf("%d %d",&m,&y);
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("=> Thang %d nam %d co 31 ngay.",m,y);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("=> Thang %d nam %d co 30 ngay.",m,y);
            break;
        case 2:
            if((y%4 == 0 && y%100 != 0) || y%400 == 0)
                printf("=> Thang %d nam %d co 29 ngay.",m,y);
            else
                printf("=> Thang %d nam %d co 28 ngay.",m,y);
            break;
        default: printf("=> Thang khong hop le.");
    }
    return 0;
}
