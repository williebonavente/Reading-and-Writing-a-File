#include <stdio.h>

int main(void)
{

    FILE *fp;
    fp = fopen("MyFamily.txt", "r");
    char code[20];

    if (fp == NULL)
    {
        printf("Error opening the file.");
        return 1;
    }

    fscanf(fp, "%s\n", code);

    printf("The value from the file is: ");
    printf("%s", code);

    fclose(fp);

    return 0;
}