// Example ni Sir no 1.

#include<stdio.h>
#include<conio.h>
#include<process.h>
struct s_friend
{
	int rollno;
	char name[50];
	int age;
	float wage;
};

main( ){

FILE *fp;
struct s_friend f;
int a;

if((fp = fopen("friendbin.dat","wb")) == 0)
{printf("Error");
	return (1);
}
for(a = 0; a < 3; a++)
{
	printf("Enter roll number: ");
	scanf("%d", &f.rollno);
	printf("Enter name: ");
	scanf("%s", &f.name);
	printf("Enter age: ");
	scanf("%d", &f.age);
	printf("Enter wage: ");
	scanf("%f", &f.wage);
	fwrite(&f, sizeof(struct s_friend),1, fp);
	}
fclose(fp);

return;
}