#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("MyFamily.txt", "w"); // write mode
    char name[15] = "Melita";
    fprintf(fp, "%s\n", name);
    fclose(fp);

    return 0;
}
