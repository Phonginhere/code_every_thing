#include <stdio.h>
#define FILE_NAME "text.txt"

int main()
{
    FILE* file_ptr = fopen(FILE_NAME, "w");
    fclose(file_ptr);

    return 0;
}
