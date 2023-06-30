#include <stdio.h>
#include <stdlib.h>

struct record
{
    char name[10];
    int age;
};

int main(void)
{
    FILE *fp;
    fp = fopen("MyData.txt", "w"); // Change mode from "r" to "w"

    if (fp == NULL)
    {
        perror("Error opening file.");
        exit(1);
    }

    struct record myfriend = {"Loyda", 23};

    fprintf(fp, "%s %d\n", myfriend.name, myfriend.age);

    fclose(fp);
    return 0;
}
