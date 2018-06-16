#include <stdio.h>
#include <stdlib.h>

// Dinh nghia kieu cau truc hang nhu duoi:
typedef struct
{
    char ten_hang[28];
    int so_luong;
    float don_gia,thanh_tien;
}hang;
long size=sizeof(hang); // Kich thuoc mot don vi du lieu kieu cau truc hang
char tep[10]={"SO_LIEU.C"}; // Tệp có tên là SO_LIEU.C
void tao_tep()
{
    FILE *fp; // Khai báo con trỏ tệp fp kiểu FILE
    hang h; // Khai báo biến cấu trúc h kiểu hang
    int i=0;
    fp=fopen(tep,"wb"); // Hàm fopen mở tệp ra để ghi theo kiểu nhập xuất nhị phân (mode "wb")
    printf("Nhap so lieu ban hang (ket thuc nhap khi khong nhap ten hang)\n");
    do
    {
        fflush(stdin); //
        printf("Nhap mat hang thu %d:\n",i++);
        printf("Ten hang: ");
        gets(h.ten_hang);
        if(h.ten_hang[0]!=0)
        {
            // Tồn tại tên hàng thì nhập dữ liệu
            printf("Don gia: ");
            scanf("%f",&h.don_gia);
            printf("So luong: ");
            scanf("%d",&h.so_luong);
            h.thanh_tien=(h.don_gia)*(h.so_luong);
            fwrite(&h,size,1,fp);
            /* Hàm fwrite ở đây để ghi 1 mặt hàng có kích thước là size(byte)
               từ vùng nhớ chứa dữ liệu cần ghi có địa chỉ đầu là &h lên tệp fp */
        }
    }while(h.ten_hang[0]!=0);
    fclose(fp); // Hàm fclose để đóng tệp, giải phóng biến con trỏ fp
}
void hien_tep()
{
    FILE *fp;
    hang h;
    float tong_tien=0;
    int i=0;
    fp=fopen(tep,"rb"); // Hàm fopen mở tệp ra để đọc theo kiểu nhập xuất nhị phân (mode "rb")
    printf("                        SO LIEU BAN HANG\n");
    printf("                        ==================\n");
    printf("STT   Ten hang   Don gia   So luong   Thanh tien\n");
    while(fread(&h,size,1,fp)>0)
    /* Tồn tại mặt hàng, hàm fread ở đây để đọc dữ liệu 1 mặt hàng có kích thước là size(byte)
       từ tệp fp chứa vào vùng nhớ có địa chỉ đầu là &h */
    {
        printf("%10d    %-15s  %10.1f %d %10.1f \n",i++,h.ten_hang,h.don_gia,h.so_luong,h.thanh_tien);
        tong_tien=tong_tien+h.thanh_tien;
    }
    printf("                 Tong tien: %f",tong_tien);
    fclose(fp);
}
void bo_sung()
{
    FILE *fp;
    hang h;
    int i=0;
    fp=fopen(tep,"ab"); // Hàm fopen mở tệp ra để ghi bổ sung theo kiểu nhập xuất nhị phân (mode "ab")
    fseek(fp,0,SEEK_END); // Hàm fseek ở đây để đặt con trỏ tệp ở cuối tệp
    i=ftell(fp)/size;
    /* Con trỏ tệp fp đang ở cuối tệp nên hàm ftell(fp) cho giá trị chính là độ dài của tệp
       Khi đó giá trị của i chính là số mặt hàng */
    printf("Bo sung so lieu ban hang (ket thuc nhap khi khong nhap ten hang)\n");
    do
    {
        fflush(stdin);
        printf("Bo sung mat hang thu %d:\n",i++);
        printf("Ten hang: ");
        gets(h.ten_hang);
        if(h.ten_hang[0]!=0)
        {
            printf("Don gia: ");
            scanf("%f",&h.don_gia);
            printf("So luong: ");
            scanf("%d",&h.so_luong);
            h.thanh_tien=(h.don_gia)*(h.so_luong);
            fwrite(&h,size,1,fp);
        }
    }while(h.ten_hang[0]!=0);
    fclose(fp);
}

int main()
{
    // Tạo Menu
    char chon;
    printf("CHON CHUC NANG CAN THUC HIEN\n");
    printf("============================\n");
    printf("1. Nhap so lieu\n");
    printf("2. Bo sung so lieu\n");
    printf("3. Hien thi noi dung\n");
    printf("4. Ket thuc\n");
    do
    {
        chon=getchar();
        switch(chon)
        {
            case '1': tao_tep(); break;
            case '2': bo_sung(); break;
            case '3': hien_tep(); break;
        }
    }while(chon!='4');
    return 0;
}
