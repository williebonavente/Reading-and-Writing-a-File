// Example no.2 ni sir
#include <stdio.h>
#include <conio.h>
#include <process.h>
struct s_friend
{
    int rollno;
    char name[50];
    int age;
    float wage;
};

main()
{

    FILE *fp;
    struct s_friend f;
    int a;

    if ((fp = fopen("friendbin.dat", "rb")) == 0)
    {
        printf("Error");
        return (1);
    }

    while (fread(&f, sizeof(struct s_friend), 1, fp))
    {
        printf("%d %s\t %d\t %.2f\n", f.rollno, f.name, f.age, f.wage);
    }

    fclose(fp);
}