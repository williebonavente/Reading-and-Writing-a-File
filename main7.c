#include<stdio.h>
#include<stdlib.h>

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
    int a;

    system("cls");

    if ((fp = fopen("friends.dat", "wt")) == NULL)
    {
        printf("Error opening the file.");
        exit(1);
    }

    for (a = 0; a < 3; a++)
    {
        printf("Enter name: ");
        scanf("%s", f.name);
        printf("Enter age: ");
        scanf("%d", &f.age);
        printf("Enter wage: ");
        scanf("%f", &f.wage);
        fprintf(fp, "%s %d %.2f\n", f.name, f.age, f.wage);
    }

    fclose(fp);

    return 0;
}
