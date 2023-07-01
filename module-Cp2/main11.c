#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    int age;
    float wage;
} record;

int main(void)
{

    FILE *fp, *tp; // file declaration
    char key;

    record myfriend; // structure declaration
    char file[12];   // filename
    int a;
    system("cls");
    printf("Enter filename: ");
    gets(file);

    if ((fp = fopen(file, "rb")) == NULL) // reading the binary file from the user input
    {
        printf("File Cannot be Processed.\n");
        return 1; // flag it 1 for unsuccessful run.
    }

    if ((tp = fopen("temp.dat", "wb")) == NULL) // file already been given
    {
        printf("File Cannot be Processed.\n");
        return 1; // flag it 1 for unsuccessful run.
    }

    while (fread(&myfriend, sizeof(record), 1, fp) != 0)
    {
        // displaying the values
        printf("Name: %s\nAge: %d\nWage: %.2f\n", myfriend.name, myfriend.age, myfriend.wage);
        printf("Edit (y/n): ");
        scanf(" %c", &key);

        if (key == 'Y' || key == 'y')
        {
            printf("Re-enter name: ");
            scanf("%s", myfriend.name);
            printf("Re-enter age: ");
            scanf("%d", &myfriend.age);
            printf("Re-enter wage: ");
            scanf("%f", &myfriend.wage);
        }

        fwrite(&myfriend, sizeof(record), 1, tp);
    }

    fclose(fp); // closing the file
    fclose(tp);
    remove(file);
    rename("temp.dat", file);

    if ((fp = fopen(file, "rb")) == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    system("cls");
    printf("\nNEW file\n");
    while (fread(&myfriend, sizeof(record), 1, fp) != 0)
    {
        printf("Name: %s\nAge: %d\nWage: %.2f\n", myfriend.name, myfriend.age, myfriend.wage);
    }

    fclose(fp);
    getch();

    return 0;
}
