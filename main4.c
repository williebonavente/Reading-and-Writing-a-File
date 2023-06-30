#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("Numbers.txt", "r");
    int count;

    if (fp == NULL)
    {
        printf("Error opening the file.");
        return 1;
    }

    fscanf(fp, "%d\n", &count); // Add & before count to pass its address

    puts("The value fetched is: ");
    printf("%d\n", count);

    fclose(fp);

    return 0;
}
