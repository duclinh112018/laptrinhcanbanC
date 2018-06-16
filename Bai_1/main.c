#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Giải phương trình bậc 2: ax2+bx+c = 0

int main()
{
    float a,b,c,delta;
    printf("+ Nhap a = ");
    scanf("%f",&a);

    printf("+ Nhap b = ");
    scanf("%f",&b);

    printf("+ Nhap c = ");
    scanf("%f",&c);

    delta = b*b - 4*a*c;

    if(delta < 0)
        printf("=> Phuong trinh vo nghiem.");
    else if(delta == 0)
        printf("=> Phuong trinh co nghiem kep : x = %f",-b/(2*a));
    else
        printf("=> Phuong trinh co 2 nghiem phan biet : \nx1 = %f, x2 = %f",(-b - sqrt(delta))/(2*a), (-b + sqrt(delta))/(2*a));
    return 0;
}
