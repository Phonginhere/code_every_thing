#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int tach(char* ho,char* s){
	strcat(ho,s); 
    printf("Ho ten la: ");
    puts(ho);
    getch();
}
int main(int argc, char *argv[]) {
    printf("1.Dem tu\n");
    printf("2.Bo ten dem\n");
    printf("3.Thoat.\n")
    char s[90],ho[100],hodem[100];
    printf("Nhap ho ban: ");gets(ho);
    printf("Nhap ho dem ban: ");gets(hodem);
    printf("Nhap ten ban: ");gets(s);
    char choice;
    LABEL1: printf("nhap so: "); choice = getchar();
    while (choice == '\n') {
        choice = getchar();
    }
    switch (choice) {
        case '1':
        		demsotu(s);
            	int kq=demsotu(s);
				printf("\nSo tu trong chuoi la: %d\n",kq);
            goto LABEL1;
            break;
        case '2':
            tach(ho, s);
            goto LABEL1;
            break;
        case '3':
            	return 0;
            	break;
			
        default:
            goto LABEL1;
            break;
    }
    return 0;
}

int demsotu(char *s)
{
	int n=strlen(s),i;
	int dem=0;
	if(s[0]!=' ')
		dem=1;
	for( i=0;i<n-1;i++)
	{
		if(s[i]==' ' && s[i+1]!=' ')
			dem++;
	}
}
