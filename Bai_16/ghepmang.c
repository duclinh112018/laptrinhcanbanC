#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100

int a[MAX],b[MAX],c[MAX],i,j,k,m,n;

void nhap_mang(int *p,int *n,char ten)
{
    printf("\nNhap kich thuoc cua mang %c: ",ten);
    scanf("%d",n);
    while(n<=0)
    {
        printf("Gia tri ban nhap cho n khong hop le, moi ban nhap lai !\n");
        printf("n=");
        scanf("%d",n);
    }
    printf("Nhap mang %c theo chieu tang dan: ",ten);
    for(i=0;i<*n;i++)
    {
        scanf("%d",p+i);
    }
}

void in_mang(int *p,int n,char ten)
{
    printf("\nMang %c: ",ten);
    for(i=0;i<n;i++)
        printf("%d\t",*(p+i));
}

void ghep_2mang(int *a,int *b,int *c,int m,int n)
{
    i=j=k=0;
    while(k<m+n)
    {
        if((i<m)&&(j<n))
        {
            if(a[i]<b[j])
               c[k++]=a[i++];
            else
               c[k++]=b[j++];
        }
        else
        {
            if(i==m)
            {
                for(;j<n;)
                    c[k++]=b[j++];
            }
            else
            {
                for(;i<m;)
                    c[k++]=a[i++];
            }
        }
    }
}

int main()
{
    char select;
    printf("CHON CHUC NANG CAN THUC HIEN:\n");
    printf("1. Nhap 2 mang\n");
    printf("2. Ghep 2 mang\n");
    printf("3. In 3 mang\n");
    printf("4. Ket thuc\n");
    do{
        select=getch();
        switch(select)
        {
            case '1':
            nhap_mang(a,&m,'a');
            nhap_mang(b,&n,'b');
            break;
            case '2':
            ghep_2mang(a,b,c,m,n);
            break;
            case '3':
            in_mang(a,m,'a');
            in_mang(b,n,'b');
            in_mang(c,m+n,'c');
        }
       }while(select!='4');
    return 0;
}
