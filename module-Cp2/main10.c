#include <stdio.h>
#include <stdlib.h>

struct s_friend
{
    char name[50];
    int age;
    float wage;
};

int main(void)
{
    FILE *fp;
    struct s_friend f;

    system("cls");

    if ((fp = fopen("friends.bin", "rb")) == NULL)
    {
        printf("Error opening the file.");
        return 1;
    }

    while (fscanf(fp, "%s%d%f", f.name, &f.age, &f.wage) != EOF)
    {
        printf("%s %d %.2f\n", f.name, f.age, f.wage);
    }


    fclose(fp);

    return 0;
}

