#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Nguoi
{
	char ten[50];
	char tuoi[50];
	char nghenghiep[100];
	
};

struct Person
{
	char name[50];
	char age[50];
	char job[50];
};
struct Product
{
	char name[50];
	char manufacture_year[50];
	char manufacter[100];
};
struct Mobile
{
	char name[50];
	char manufacture_year[50];
	char manufacter[100];
};
int main(int argc, char *argv[]) {
	//About a personality
	//Nguoi
	struct Nguoi Nguoithunhat;
	//Person
	struct Person  Person1;
	//thong tin nguoithunhat
	strcpy(Nguoithunhat.ten, "Tran Hai Phong");
	strcpy(Nguoithunhat.tuoi, "14");
	strcpy(Nguoithunhat.nghenghiep, "Hoc Vien");
	//information about first person
	strcpy(Person1.name, "Tran Hai Phong");
	strcpy(Person1.age, "14");
	strcpy(Person1.job, "Student");
	//hien thi nguoi thu nhat
	printf("Ten: %s\n", Nguoithunhat.ten);
	printf("Tuoi: %s\n ", Nguoithunhat.tuoi);
	printf("Nghe Nghiep: %s\n", Nguoithunhat.nghenghiep);
	// show first person
	printf("\nName: %s\n",Person1.name );
	printf("Age: %s\n ",Person1.age);
	printf("Job: %s\n", Person1.job);
	
	//About Technology
	struct Product NividaQuadroP2000;
	//thong tin ve san pham
	strcpy(NividaQuadroP2000.name, "NividaQuadroP2000");
	strcpy(NividaQuadroP2000.manufacture_year, "2018");
	strcpy(NividaQuadroP2000.manufacter, "Nivida Cooperation");
	// show about this
	printf("\nName : %s\n", NividaQuadroP2000.name);
	printf("Manufacture_year: %s\n", NividaQuadroP2000.manufacture_year);
	printf("Manufacter: %s\n", NividaQuadroP2000.manufacter);
	//About Mobile
	struct Mobile SamsungGalaxyFold;
	//thong tin ve san pham
	strcpy(SamsungGalaxyFold.name, "SamsungGalaxyFold");
	strcpy(SamsungGalaxyFold.manufacture_year, "2019");
	strcpy(SamsungGalaxyFold.manufacter, "Samsung");
	// show about this
	printf("\nName : %s\n", SamsungGalaxyFold.name);
	printf("Manufacture_year: %s\n", SamsungGalaxyFold.manufacture_year);
	printf("Manufacter: %s\n", SamsungGalaxyFold.manufacter);
	
	
	
	
	return 0;
}
