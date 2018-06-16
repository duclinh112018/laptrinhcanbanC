#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,d,e,f,D,Dx,Dy;
    printf("+ Nhap he so a, b, c : ");
    scanf("%f %f %f",&a,&b,&c);

    printf("+ Nhap he so d, e, f : ");
    scanf("%f %f %f",&d,&e,&f);

    D = a*e - b*d;
    Dx = c*e - b*f;
    Dy = a*f - c*d;

    if(D != 0)
        printf("=> He phuong trinh co nghiem duy nhat:\n x = %f, y = %f",Dx/D,Dy/D);
    else
    {
        if(Dx != 0 || Dy != 0)
            printf("=> He phuong trinh vo nghiem.");
        if(Dx == 0 && Dy == 0)
            printf("=> He phuong trinh co vo so nghiem.");
    }
    return 0;
}
