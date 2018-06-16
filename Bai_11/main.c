#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien
{
    char ten[30];
    int tuoi;
    float dtb;
};
typedef struct SinhVien SV;

struct Node
{
    SV info;
    struct Node *pNext;
};
typedef struct Node NODE;

struct List
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct List LIST;

void creat_list(LIST *l)
{
    (*l).pHead = (*l).pTail = NULL;
}

NODE* get_node(SV x)
{
    NODE *p;
    p = (NODE *)malloc(1*sizeof(NODE));
    if(p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void input_data(SV *x)
{
   fflush(stdin);
   printf(" + Nhap ho ten : ");
   gets((*x).ten);
   fflush(stdin);
   printf(" + Nhap tuoi : ");
   scanf("%d",&(*x).tuoi);
   fflush(stdin);
   printf(" + Nhap diem TB : ");
   scanf("%f",&(*x).dtb);
}

void add_Tail(LIST *l, NODE *p)
{
    if((*l).pHead == NULL)
    {
        (*l).pHead = (*l).pTail = p;
    }
    else
    {
        (*l).pTail->pNext = p;
        (*l).pTail = p;
    }
}

void add_back(LIST *l)
{
    SV them;
    char name[30];
    fflush(stdin);
    printf("- Nhap thong tin sinh vien can them : \n");
    printf(" + Nhap ho ten : ");
    gets(them.ten);
    printf(" + Nhap tuoi : ");
    scanf("%d",&them.tuoi);
    fflush(stdin);
    printf(" + Nhap diem TB : ");
    scanf("%f",&them.dtb);
    fflush(stdin);
    printf("\n=> Nhap ten sinh vien can them vao sau : ");
    gets(name);
    NODE *p = get_node(them);
    NODE *k;
    int count = 0;
    for (k = (*l).pHead; k != NULL; k = k->pNext)
    {
        if(strcmp(name,k->info.ten)==0)
        {
            if(k != NULL)
            {
                p->pNext = k->pNext;
                k->pNext = p;
                if(k == (*l).pTail)
                    (*l).pTail = p;
            }
            count++;
        }
    }
    if(count == 0)
        printf("Khong tim thay sinh vien !");
}

void delete_head(LIST *l)
{
    if((*l).pHead == NULL)
        return;
    else
    {
        NODE *p = (*l).pHead;
        (*l).pHead = (*l).pHead->pNext;
        free(p);
    }
}

void delete_tail(LIST *l)
{
    if((*l).pHead == NULL)
        return;
    else
    {
        NODE *k;
        for (k = (*l).pHead; k != NULL; k = k->pNext)
        {
            if(k->pNext == (*l).pTail)
            {
                free((*l).pTail);
                k->pNext = NULL;
                (*l).pTail = k;
            }
        }
    }
}


int xoa(LIST *l)
{
    char name[30];
    fflush(stdin);
    printf("+ Nhap ten sinh vien can xoa : ");
    gets(name);
    int dem = 0;
    if(strcmp((*l).pHead->info.ten, name) == 0)
    {
        delete_head(&(*l));
        dem++;
        return dem;
    }
    else if(strcmp((*l).pTail->info.ten, name) == 0)
    {
        delete_tail(&(*l));
        dem++;
        return;
    }
    else
    {
        dem++;
        NODE *k;
        NODE *g = (NODE *) malloc(1*sizeof(NODE *));
        for (k=(*l).pHead; k != NULL; k = k->pNext)
        {
            if(strcmp(k->info.ten, name) == 0)
            {
                g->pNext = k->pNext;
                free(k);
            }
            g = k;
        }
    }
}

int sua_sv(LIST l)
{
    SV x;
    char name[30];
    fflush(stdin);
    printf("- Nhap ten sinh vien can sua : ");
    gets(name);
    NODE *k;
    int dem = 0;
    for (k=l.pHead; k != NULL; k = k->pNext)
    {
        if(strcmp(k->info.ten, name) == 0)
        {
            dem++;
            fflush(stdin);
            printf("- Nhap thong tin sinh vien can sua : \n");
            printf("+ Nhap ho ten : ");
            gets(x.ten);
            printf("+ Nhap tuoi : ");
            scanf("%d",&x.tuoi);
            fflush(stdin);
            printf("+ Nhap dtb : ");
            scanf("%f",&x.dtb);
            fflush(stdin);
            NODE *g = get_node(x);
            k->info = g->info;
        }
    }
    return dem;
}


void nhap_sv(LIST *l)
{
    SV x;
    int n;
    printf("- Nhap so luong sinh vien : ");
    scanf("%d",&n);
    int i;
    for (i=0; i<n; i++)
    {
        printf("\n- Nhap thong tin sinh vien thu %d: \n",i+1);
        input_data(&x);
        NODE *k = get_node(x);
        add_Tail(&(*l),k);
    }
}


void output_data(SV x, int i)
{
    printf("\t\t%-5d %-20s %-5d %-5f\n",i,x.ten,x.tuoi,x.dtb);
}

void xuat_sv(LIST l)
{
    NODE *p;
    printf("\t\t=========== DANH SACH SINH VIEN ===========\n");
    printf("\t\t%-5s %-20s %-5s %-5s\n","STT","HO_TEN", "TUOI", "DIEM_TB");
    int i=1;
    for (p = l.pHead; p != NULL; p = p->pNext)
    {
        output_data(p->info,i);
        i++;
    }
}



int main()
{
    LIST l;
    int choice;
    int dem1, dem2;
    do
    {
        printf("\t\t================= MENU ================\n");
        printf("\t\t=      1. Tao danh sach sinh vien     =\n");
        printf("\t\t=      2. Hien thi danh sach          =\n");
        printf("\t\t=      3. Chen them sinh vien         =\n");
        printf("\t\t=      4. Xoa mot sinh vien           =\n");
        printf("\t\t=      5. Sua mot sinh vien           =\n");
        printf("\t\t=      6. Thoat                       =\n");
        printf("\t\t=======================================\n");

        printf("\t=> Moi ban chon : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: creat_list(&l); nhap_sv(&l); break;
            case 2: xuat_sv(l); printf("\n"); break;
            case 3: add_back(&l); printf("\n"); break;
            case 4:
                dem1 = xoa(&l);
                if(dem1 == 0)
                    printf("=> Khong tim thay sinh vien can xoa.");
                else
                    printf("=> Xoa thanh cong.");
                printf("\n"); break;
            case 5:
                dem2 = sua_sv(l);
                if(dem2 == 0)
                    printf("=> Khong tim thay sinh vien can sua.");
                else
                    printf("=> Da sua sinh vien.");
            default: printf("Ban nhap khong dung!");
        }
    }while(choice != 6);
    return 0;
}
