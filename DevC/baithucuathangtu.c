#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	   	char name [100], y, i;
            char sanpham[y],temp;
			for (i = 0; i < y; i++){
				printf("Nhap chi tiet san pham=  "); scanf("%s",&sanpham[y].name);
				} goto Ten;*/
			 	printf("\nBan muon lam gi voi du lieu nay? = "); scanf("%c",&o); 
				o = getchar();
				switch(o){
					case '2': 
		      				for(i = 0; i <= y; i++){
								for(j = i + 1; j <= y; j++){
									if (sanpham[j].name> sanpham[j + 1].name) {
									temp = sanpham[j];
									sanpham[j] = sanpham[j + 1];
									sanpham[j + 1] = temp;
								}
							}
						}
							for(i = 0; i < y; i++){
							printf("%s\n", sanpham[i].name);
				}
						break;
					case '3':
					    Ten: for(i = 0; i < y; i++){
						printf("Cac san pham la:%s\n",sanpham[y].name);
					}
						
						break;
					case '4':
						return 0;
						break;
					}
	   					getchar();
			} getchar(); 
	return 0;
}
