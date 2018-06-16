#include <stdio.h>
#include <stdlib.h>

int main()
{
    float gdp,tocdo;
    int nam = 2014;

    printf("+ Nhap GDP nam 2014 : ");
    scanf("%f",&gdp);

    printf("+ Nhap toc do tang truong : ");
    scanf("%f",&tocdo);

    int temp = 2*gdp;
    printf("\t%-10s %-10s\n","NAM", "GDP");
    printf("\t%-10d %-10.2f\n",nam,gdp);

    while(gdp < temp)
    {
        gdp *= tocdo;
        nam++;
        printf("\t%-10d %-10.2f\n",nam,gdp);
    }
    return 0;
}
