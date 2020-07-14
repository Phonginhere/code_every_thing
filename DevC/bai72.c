#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Book{
	char name[50];
	char cate[30];
	int price;
};
int N;
struct Book* input() {
    printf("Nhap so sach: "); scanf("%d", &N);
    struct Book *book = (struct Book *)malloc(N * sizeof(struct Book));
    int i;
    for (i = 0; i < N; i++) {
        INPUT_ONE: 
		printf("Sach [%d]: \n", i+1);
        printf("Nhap ten sach : ");scanf("%s", (book+i)->name);
        printf("Nhap the loai : "); scanf("%s", (book+i)->cate);
        printf("Nhap gia tien:");scanf("%d", &(book+i)->price);
    }
    return book;
}
void display(struct Book* book) {
    int i, numberOfBooks;
    numberOfBooks = 0;
    for (i = 0; i < N && (book + i)->year > 0; i++) {
        printf("|%s", (*(book+i)).name);
        printf("|%s", (*(book+i)).cate);
        printf("|%d\n", (*(book+i)).price);
        printf("-------------------------------------------------\n");
        numberOfBooks++;
    }
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("%d book(s) found \n", numberOfBooks);
}
void sort(struct Book* book) {
    int i, j;
    for(i = 0; i < N-1; i++){
        for (j = i + 1; j < N; j++) {
            if(strcmp( (book+i)->name, (book + j)->name) > 0) {
                struct Book temp;
                temp = *(book + i);
                *(book + i) = *(book + j);
                *(book + j) = temp;
            }
        }
    }
    display(book);
}
void analyze(struct Book* book) {
    char publishers[N][250];
    int i,j;
    for (i = 0; i < N; i++) {
        strcpy(publishers[i], (book+i)->cate);
    }
    //2.sort ascending(alphabet)
    for (i = 0; i < N-1; i++) {
        for (j = i+1; j < N; j++) {
            if(strcmp(publishers[i], publishers[j]) > 0) {
                char temp[150];
                //swap publishers[i] and publishers[j]
                strcpy(temp, publishers[i]);
                strcpy(publishers[i], publishers[j]);
                strcpy(publishers[j], temp);
            }
        }
    }
    printf("Ket qua phan tich: \n");
    char publisherName[150];
    int count = 0;
    for (i = 0; i < N; i++) {
        if(i == 0) {
            strcpy(publisherName, publishers[i]);
            count++;
        } else if(strcmp(publishers[i], publisherName) != 0){
            printf("+Co %d cuon sach thuoc loai %s\n", count, publisherName);
            strcpy(publisherName, publishers[i]);
            count = 1;
        } else if(strcmp(publishers[i], publisherName) == 0) {
            count++;
        }
    }
    if(N >0){
        printf("+Co %d cuon sach thuoc the loai %s\n", count, publisherName);
    }
}
void save(struct Book* book) {
    char fileName[250];//Include detail path
    printf("Nhap ten file: "); scanf("%s", fileName);
    FILE* file = fopen(fileName, "wb"); //wb = write binary
    if(file == NULL){
        printf("Khong the mo tep %s\n", fileName);
    } else{
        fwrite(book, sizeof(struct Book *), N, file);
        fclose(file);
        printf("DATA da luu thanh cong \n");
    }
}
void openFile(struct Book *book) {
    char fileName[250];
    printf("Nhap ten file de mo : "); scanf("%s", fileName);
    FILE *file = fopen(fileName,"rb"); // r for read, b for binary
    if (!file) {
        printf("Khong the mo file %s\n", fileName);
    } else {
        fread(book, sizeof(struct Book), N, file);
        display(book);
        fclose(file);
    }
}
int main(int argc, char *argv[]) {
	int choice;
LABEL1:printf("1.Nhap thong tin cuon sach\n");
	printf("2.Sap xep va hien thi thong tin chi tiet cac cuon sach theo thu tu tang dan cua ten sach (A-Z)\n");
	printf("3.Thong ke so luong theo the loai\n");
	printf("4.Tim sach theo the loai va gia tien\n");
	printf("5.Luu danh sach vao tap tin book.dat\n");
	printf("6.Doc danh sach ra tu file\n");
	printf("7.Thoat\n");
	printf("Nhap so:"); scanf("%d", &choice);
	switch(choice){
		case 1:	book = input();
				goto LABEL1;
				break;
		case 2:	sort(book);
				goto LABEL1;
				break;
		case 3:	analyze(book);
				goto LABEL1;
				break;
		case 4:	find(book);
				goto LABEL1;
				break;
		case 5:	save(book);
				goto LABEL1;
				break;
		case 6:	open(book);
				goto LABEL1;
				break;	
		case 7:	break;	
		default: goto LABEL1;
				break;		
	}
	return 0;
}
