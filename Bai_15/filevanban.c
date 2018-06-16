/*
Viết chương trình tính tích hai ma trận Cmxp=Amxn*Bnxp.Trong đó dữ liệu về m,n,p và nội dung hai ma trận A, B được lưu trữ trên tệp Matrix.C theo dạng sau:
    + Dòng đầu tiên ghi: m  n  p
    + Dòng tiếp theo ghi: Ma trận A; các dòng tiếp theo là các hàng của ma trận A; dòng tiếp theo ghi: Ma trận B; các dòng tiếp theo là các hàng của ma trận B
Chương trình được tổ chức thành các công việc và các chương trình con sau:
1)	Tạo tệp Matrix.C theo cấu trúc như trên (giống như soạn thảo một chương trình C)
2)	Đọc tệp Matrix.C
3)	Tính ma trận tích C rồi ghi bổ sung vào cuối tệp trên(sử dụng kiểu nhập xuất văn bản)
4)	Mở tệp Matrix.C để xem kết quả
Hàm main() hiển thị menu để chọn các chức năng bằng cách nhập số tương ứng như sau:
1.	Doc tep ma tran A,B tu tep
2.	Tinh ma tran C va ghi bo sung vao cuoi tep
3.	Ket thuc

1) Soạn thảo nội dung tệp MA_TRAN.C có dạng sau:

2 3 4
Ma tran A:
1  2  3
4  5  6
Ma tran B:
-2  3   5   6
7   8   9   1
-8  2   1   3

2) Viết chương trình: */

#include <stdio.h>
#include <conio.h>
#define MAX 100

FILE *fp;
int m,n,p,i,j,k,A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];
char chon,s[MAX];

void doc_tep()
{
    fp=fopen("Matrix.C","r"); // Mở tệp Matrix.C để đọc dữ liệu tệp vào bộ nhớ
    fscanf(fp,"%d%d%d",&m,&n,&p); // Đọc dữ liệu từ tệp Matrix.C theo khuôn dạng số nguyên và lưu kết quả vào các đối m,n,p
    fgets(s,100,fp); // Đọc hết dòng đầu tiên của tệp Matrix.C
    fgets(s,100,fp); // Đọc hết dòng thứ hai của tệp Matrix.C ("Ma tran A:")
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            fscanf(fp,"%d",&A[i][j]);
        // Đọc nội dung của ma trận A từ tệp vào bộ nhớ
    }
    fgets(s,100,fp); // Đọc hết dòng thứ tư của tệp Matrix.C
    fgets(s,100,fp); // Đọc hết dòng "Ma tran B:" của tệp Matrix.C
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
            fscanf(fp,"%d",&B[i][j]);
        // Đọc nội dung của ma trận B từ tệp vào bộ nhớ
    }
    fclose(fp); // Đóng tệp Matrix.C
}

void Matrix_C()
{
    fp=fopen("Matrix.C","a"); // Mở tệp Matrix.C để ghi dữ liệu bổ sung vào cuối tệp
    fprintf(fp,"\nMa tran tich:\n"); // Ghi đoạn text "\nMa tran tich:\n" vào tệp Matrix.C
    // Code tính ma trận tích
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
        {
            C[i][j]=0;
            for(k=0;k<n;k++)
                C[i][j]+=A[i][k]*B[k][j];
        }
    }
    // Code ghi nội dung của ma trận tích từ bộ nhớ lên tệp
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
            fprintf(fp,"%6d",C[i][j]);
        fprintf(fp,"\n");
    }
    fclose(fp);
}

int main()
{
    printf("CHON CHUC NANG CAN THUC HIEN\n");
    printf("============================\n");
    printf("1. Doc tep ma tran A,B tu tep\n");
    printf("2. Tinh ma tran C va ghi bo sung vao cuoi tep\n");
    printf("3. Ket thuc\n");
    do
    {
        chon=getch();
        switch(chon)
        {
            case '1': doc_tep(); break;
            case '2': Matrix_C(); break;
        }
    }while(chon!='3');
    return 0;
}

// 3) Xem lại nội dung tệp Matrix.C sau khi đã ghi bổ sung ma trận tích vào cuối tệp
