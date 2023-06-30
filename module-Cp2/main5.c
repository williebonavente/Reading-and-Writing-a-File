#include <stdio.h>

struct record
{
    char name[10];
    int age;
};

int main(void)
{
    FILE *fp;
    fp = fopen("MyData.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening the file.");
        return 1;
    }

    struct record myfriend;

    fscanf(fp, "%s %d", myfriend.name, &myfriend.age);
    printf("Here are the values taken from the file:\n");
    printf("%s %d\n", myfriend.name, myfriend.age);

    fclose(fp);
    return 0;
}
