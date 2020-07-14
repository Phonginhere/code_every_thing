#include <io.h>
#include <dos.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[5]={10,2,10,4,5};

main() {
	FILE *fp;
	fd=_creat ("file.txt", "w");
	fputs("OKAAAYAYAYAYAY\n", fp);
	fclose(fp);
	return 0;
}
