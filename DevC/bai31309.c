#include <stdio.h>
#include <stdlib.h>
int main() {
	int marks;
	printf("nhap so diem tu 0--->100: ");
	scanf("%d", &marks);
	if (marks < 35) {
		printf("\ngrade E");
	} else if (marks > 35 && marks < 45) {
		printf ("\ngrade D");
	}  else if (marks > 45 && marks < 60) {
		printf ("\ngrade C");
	}  else if (marks > 60 && marks < 75) {
		printf ("\ngrade B, tien thuong 250k");
	}  else if (marks > 75 && marks < 100) {
		printf ("\ngrade A, tien thuong 300k");
	} else {
		printf("\nbao loi");
		return 0;
	}
	return 0;
}
