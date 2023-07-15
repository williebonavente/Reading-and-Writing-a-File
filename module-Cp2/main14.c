#include <stdio.h>
#include <malloc.h>
struct student
{
    int rno;
    char name[20];
    struct subject
    {
        int scode;
        char sname[20];
        int mark;
    } sub[3];
    int total;
    float percentage;
};
void create()
{
    struct student *s;
    FILE *fp;
    int n, i, j;
    printf("How manystudents you want?: ");
    scanf("%d", &n);
    s = (struct student *)malloc(n * sizeof(struct student));
    fp = fopen("record.txt", "w");
    for (i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].percentage = 0;
        printf("Enter Roll Number: ");
        scanf("%d", &s[i]);
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s", s[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("Enter mark of subject %d : ", j + 1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].percentage = s[i].total / 3.0;
        fwrite(&s[i], sizeof(struct student), 1, fp);
    }
    fclose(fp);
}
void display()
{
    struct student studentrec;
    FILE *fp;
    int j;
    fp = fopen("record.txt", "r");
    while (fread(&studentrec, sizeof(struct student), 1, fp))
    {
        printf("\n%-5d%-20s", studentrec.rno, studentrec.name);
        for (j = 0; j < 3; j++)
        {
            printf("%5d", studentrec.sub[j].mark);
        }
        printf("%5d%7.2f", studentrec.total, studentrec.percentage);
    }
    fclose(fp);
}
void append()
{
    struct student *s;
    FILE *fp;
    int n, i, j;
    printf("How many students you want?: ");
    scanf("%d", &n);
    fflush(stdin);
    s = (struct student *)malloc(n * sizeof(struct student));
    fp = fopen("record.txt", "a");
    for (i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].percentage = 0;
        printf("Enter Roll Number: ");
        scanf("%d", &s[i]);
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s", s[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("Enter mark of subject %d : ", j + 1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].percentage = s[i].total / 3.0;
        fwrite(&s[i], sizeof(struct student), 1, fp);
    }
    fclose(fp);
}
noOfRecords()
{
    struct student studentrec;
    FILE *fp;
    fp = fopen("record.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(struct student);
    printf("\nNumber of records: %d\n", n);
    fclose(fp);
}
search()
{
    struct student studentrec;
    FILE *fp;
    int j;
    int found = 0;
    int rollNumber;
    fp = fopen("record.txt", "r");
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);
    while (fread(&studentrec, sizeof(struct student), 1, fp))
    {
        if (studentrec.rno == rollNumber)
        {
            found = 1;
            printf("\n%5d%20s", studentrec.rno, studentrec.name);
            for (j = 0; j < 3; j++)
            {
                printf("%5d", studentrec.sub[j].mark);
            }
            printf("%5d%7.2f", studentrec.total, studentrec.percentage);
        }
    }
    if (found == 0)
    {
        printf("\nRecord not found\n");
    }
    fclose(fp);
}
void update()
{
    struct student studentrec;
    FILE *fp, *fp1;
    int j;
    int found = 0;
    int rollNumber;
    fp = fopen("record.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("Enter roll number to update: ");
    scanf("%d", &rollNumber);
    while (fread(&studentrec, sizeof(struct student), 1, fp))
    {
        if (studentrec.rno == rollNumber)
        {
            studentrec.total = 0;
            studentrec.percentage = 0;
            found = 1;
            fflush(stdin);
            printf("Enter new name: ");
            scanf("%[^\n]s", studentrec.name);
            for (j = 0; j < 3; j++)
            {
                printf("Enter new mark of subject %d : ", j + 1);
                scanf("%d", &studentrec.sub[j].mark);
                studentrec.total += studentrec.sub[j].mark;
            }
            studentrec.percentage = studentrec.total / 3.0;
        }
        fwrite(&studentrec, sizeof(struct student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (found)
    {
        fp1 = fopen("temp.txt", "r");
        fp = fopen("record.txt", "w");
        while (fread(&studentrec, sizeof(struct student), 1, fp1))
        {
            fwrite(&studentrec, sizeof(struct student), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        printf("\nRecord not found\n");
    }
}
void delete()
{
    struct student studentrec;
    FILE *fp, *fp1;
    int j;
    int found = 0;
    int rollNumber;
    fp = fopen("record.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNumber);
    while (fread(&studentrec, sizeof(struct student), 1, fp))
    {
        if (studentrec.rno == rollNumber)
        {
            found = 1;
        }
        else
        {
            fwrite(&studentrec, sizeof(struct student), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    if (found)
    {
        fp1 = fopen("temp.txt", "r");
        fp = fopen("record.txt", "w");
        while (fread(&studentrec, sizeof(struct student), 1, fp1))
        {
            fwrite(&studentrec, sizeof(struct student), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        printf("\nRecord not found\n");
    }
}
void sort()
{
    struct student *stud, stud1;
    int i, j;
    FILE *fp;
    fp = fopen("record.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(struct student);
    stud = (struct student *)malloc(n * sizeof(struct student));
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fread(&stud[i], sizeof(struct student), 1, fp);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (stud[i].total < stud[j].total)
            {
                stud1 = stud[i];
                stud[i] = stud[j];
                stud[j] = stud1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\n%-5d%-20s", stud[i].rno, stud[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("%5d", stud[i].sub[j].mark);
        }
        printf("%5d%7.2f", stud[i].total, stud[i].percentage);
    }
    fclose(fp);
}
int main()
{
    int ch;
    do
    {
        printf("\n[1] CREATE");
        printf("\n[2] DISPLAY");
        printf("\n[3] APPEND");
        printf("\n[4] NO. OF RECORDS");
        printf("\n[5] SEARCH A RECORD");
        printf("\n[6] UPDATE");
        printf("\n[7] DELETE");
        printf("\n[8] SORT");
        printf("\n[0] EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            append();
            break;
        case 4:
            noOfRecords();
            break;
        case 5:
            search();
            break;
        case 6:
            update();
            break;
        case 7:
            delete ();
            break;
        case 8:
            sort();
            break;
        default:
            break;
        }
    } while (ch != 0);
    return 0;
}