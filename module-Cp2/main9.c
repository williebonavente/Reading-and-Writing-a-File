#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *fp;

    fp = fopen("MyFamily.txt", "r"); // read mode
    char code[20];

    printf("The value from the file is: ");

    while (fscanf(fp, "%s\n", code) != EOF)
    {
        printf("%s\n", code);
    }

    fclose(fp);
    return 0;
}

