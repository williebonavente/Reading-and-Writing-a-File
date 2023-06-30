#include <stdio.h>
#include <stdlib.h>

int  main()
{
    FILE *fp;
    fp = fopen("Numbers.txt", "w");
    int age;
    puts("How old are you?");
    scanf("%d", &age);
    fprintf(fp, "Input Age: %d\n", age);
    fclose(fp);

    return 0;
}
