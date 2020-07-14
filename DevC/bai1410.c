#include <stdio.h>

void nhapHaiSo(int &a, int &b)
{
    printf("Nhap so nguyen a = ");
    scanf("%d", &a);
    printf("Nhap so nguyen b = ");
    scanf("%d", &b);
}

void tongHaiSo(int a, int b)
{
    printf("Tong hai so la: %d\n", a + b);
}

void hieuHaiSo(int a, int b)
{
    printf("Hieu hai so la: %d\n", a - b);
}

int main()
{
    int x, y, select, dk;

    x = y = 0;
    dk = 1;

    do
    {
        printf("\n1. Nhap 2 so nguyen\n");
        printf("2. Tinh tong\n");
        printf("3. Tinh hieu\n");
        printf("4. Thoat\n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            nhapHaiSo(x, y);
            break;
        case 2:
            tongHaiSo(x, y);
            break;
        case 3:
            hieuHaiSo(x, y);
            break;
        case 4:
            printf("Thoat khoi chuong trinh\n");
            dk = 0;
            break;
        default:
            printf("Nhap sai. Moi nhap lai\n");
            break;
        }
    } while (dk);

    return 0;
}
