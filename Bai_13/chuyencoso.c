/* Viết chương trình đổi một số thập phân n>=0 nhập vào từ bàn phím sang các cơ số 2, 8, 16 bằng cách dùng cấu trúc dữ liệu STACK
Chương trình được tổ chức thành các chương trình con sau:
1) Hàm push(): Thêm một phần tử vào ngăn xếp
2) Hàm pop(): Xóa một phần tử khỏi ngăn xếp
3) Hàm doi_coso(): Đổi một số thập phân n>=0 sang cơ số bất kì
4) Hàm hien_kq(): Hiển thị kết quả ra màn hình
Hàm main() xây dựng menu để chọn các chức năng bằng cách nhập số tương ứng như sau:
1. Doi so sang he co so 2
2. Doi so sang he co so 8
3. Doi so sang he co so 16
4. Ket thuc
Chức năng nào được chọn sẽ gọi chương trình con truyền tham số tương ứng */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node *next;
}Stack;
Stack *top,*p;
int n;
char chon;

void push(int n)
{
    p=(Stack*)malloc(sizeof(Stack));
    p->number=n;
    p->next=top;
    top=p;
}

void pop(int *m)
{
    p=top;
    *m=p->number;
    top=p->next;
    free(p);
}

void doi_coso(int n,int coso)
{
    top=NULL;
    while(n!=0)
    {
         push(n%coso);
         n=n/coso;
    }
}

void hien_kq(int n,int coso)
{
    int so_du;
    printf("Doi %d sang he co so %d la ",n,coso);
    while(top!=NULL) // Khi Stack chua rong
    {
        pop(&so_du);
        if(so_du<10)
           printf("%d",so_du);
        else
           printf("%c",so_du+55);
    }
    printf("\n");
}

int main()
{
    printf("Nhap gia tri cho n: n=");
    scanf("%d",&n);
    printf("\nCHON CHUC NANG CAN THUC HIEN\n");
    printf("============================\n");
    printf("1. Doi so sang he co so 2\n");
    printf("2. Doi so sang he co so 8\n");
    printf("3. Doi so sang he co so 16\n");
    printf("4. Ket thuc\n\n");
    do
    {
        chon=getch();
        switch(chon)
        {
            case '1': doi_coso(n,2); hien_kq(n,2); break;
            case '2': doi_coso(n,8); hien_kq(n,8); break;
            case '3': doi_coso(n,16); hien_kq(n,16); break;
        }
    }while(chon!='4');
    return 0;
}
