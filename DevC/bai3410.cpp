#include <stdio.h>

int main()
{
    int x, y, select;

    BACK:do
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
        	printf("Nhap so nguyen x = ");
    		scanf("%d", &x);
    		printf("Nhap so nguyen y = ");
    		scanf("%d", &y);
            goto BACK;
            break;
        case 2:
            printf("Tong hai so la: %d\n", x + y);
            goto BACK;
            break;
        case 3:
        	printf("Hieu hai so la: %d\n", x - y);
            goto BACK;
            break;
        case 4:
            printf("Thoat khoi chuong trinh\n");
            break;
        }
    } while (select > 4 || select < 1);

    return 0;
}
