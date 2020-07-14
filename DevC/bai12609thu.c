#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *s1;
	s1 = (char *)malloc(100 * sizeof(char));
	printf("xin moi ban nhap chuoi"); gets(s1);
	int i;
	for(i=0; i< strlen(s1)/2; i++){
		if(s1[i] != s1[strlen(s1)-1-i])
		 {
        return 0;
        }
        return 1;
    }
	if(doixung(s1)==0)
            {
                        printf("chuoi vua nhap khong phai chuoi doi xung\n");
            }
            else if(doixung(s1)==1)
            {
                        printf("chuoi vua nhap la chuoi doi xung\n");
            } return 0;
}
