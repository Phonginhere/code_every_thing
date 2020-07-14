#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct item{
	char san_pham [50];
	char ty_le [50];
	char so_luong_cua_san_pham [50];
};
int main(int argc, char *argv[]) {
	int select, N, i;
	
	printf("1.Input some Items\n");
	printf("2.Sort\n");
	printf("3.Dispaly\n");
	printf("4.Exit\n");
	printf("nhap so: "); scanf("%d", &select);
	switch (select){
		case 1: printf("nhap so luong san pham: "); scanf("%d", &N);
				struct item * sanpham;
				sanpham = (struct item *)
					malloc(sizeof(struct sanpham *));
					for(i = 1; i <= N; i++){
						printf("nhap san pham[%d]:", i); scanf("%s",(*sanpham). san_pham);
						printf("nhap ty le[%d]: ", i); scanf("%s",(*sanpham). ty_le);
						printf("so luong trong 1 san pham do[%d]: ", i); scanf("%d",(*sanpham). so_luong_cua_san_pham);
						printf("------------------------------------\n");
					}
	}
	return 0;
}
