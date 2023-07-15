#include <stdio.h>
#include <stdlib.h>
#define MAX_FILENAME 50
/*
WILLIE M. BONAVENTE
BSIT 1-5
*/
struct grade_t
{
char name[50];
float midterm_grade;
float final_grade;
};
void display_table(struct grade_t grade);
int scanFile(FILE *file);
int savingToFile(FILE *file, struct grade_t *grades, int num_records);
int main(void)
{
FILE *file;
char filename[MAX_FILENAME];
printf("Enter the filename for the record to be saved in >> ");
scanf("%s", filename);
file = fopen(filename, "w");
if (file == NULL)
{
printf("Error opening file.\n");
return 1; // Return 1 to indicate an error occurred
}
// Call the scanFile function and pass the file pointer as an argument
int result = scanFile(file);
// Check the result
if (result == 1)
{
printf("File scanning completed successfully.\n");
printf("\n");
}
else
{
printf("Error occurred during file scanning.\n");
}
// Declaring necessary variables
int num_records = 0;
char another_record = 'n';
int i;
// Dynamic memory allocation for grade records
struct grade_t *grades = NULL;
do
{
// Reallocate memory for additional record

num_records++;
grades = realloc(grades, num_records * sizeof(struct grade_t));
// Input record details
printf("Enter name: ");
scanf("%s", grades[num_records - 1].name);
printf("Enter midterm grade: ");
scanf("%f", &grades[num_records - 1].midterm_grade);
printf("Enter final grade: ");
scanf("%f", &grades[num_records - 1].final_grade);
printf("Do you want to enter another record? (y/n): ");
scanf(" %c", &another_record);
printf("\n");
} while (another_record == 'y' || another_record == 'Y');
system("cls");
printf("\n");
// Display table headers
printf("\tName\t\t\tMidterm\t\tFinal Grade\tAve.grade\n");
// Display records
for (i = 0; i < num_records; i++)
{
display_table(grades[i]);
}
// Pass the file pointer, grades array, and num_records to the savingToFile function
savingToFile(file, grades, num_records);
// Close the file
fclose(file);
// Free allocated memory
free(grades);
return 0;
}
void display_table(struct grade_t grade)
{
// Calculate average grade
float ave_grade = (grade.midterm_grade + grade.final_grade) / 2;
// Display record
printf("\t%-25s%-18.2f%-15.2f%.2f\n", grade.name,
grade.midterm_grade, grade.final_grade, ave_grade);
}
int scanFile(FILE *file)
{
if (file == NULL)
{
printf("Error opening file.\n");
return 0;
}
char line[100];
while (fgets(line, sizeof(line), file))
{
char name[50];
float midtermGrade, finalGrade;
if (sscanf(line, "%s %f %f", name, &midtermGrade, &finalGrade) == 3)
{
// Perform operations with the extracted data
// Example: Calculate the average grade
float averageGrade = (midtermGrade + finalGrade) / 2;
// Print the extracted data and calculated average grade
printf("Name: %s\n", name);

printf("Midterm Grade: %.2f\n", midtermGrade);
printf("Final Grade: %.2f\n", finalGrade);
printf("Average Grade: %.2f\n", averageGrade);
// Perform additional operations as needed
}
}
return 1;
}
int savingToFile(FILE *file, struct grade_t *grades, int num_records)
{
int i;
if (file == NULL)
{
printf("Error opening file.\n");
return 0;
}
fprintf(file, "\t%-25s\t%-10s\t%-12s\t%-9s\n", "Name", "Midterm", "Final Grade",
"Ave.grade");
for (i = 0; i < num_records; i++)
{
float ave_grade = (grades[i].midterm_grade + grades[i].final_grade) / 2;
fprintf(file, "\t%-25s\t%-10.2f\t%-12.2f\t%-9.2f\n", grades[i].name,
grades[i].midterm_grade, grades[i].final_grade, ave_grade);
}
printf("\n\n");
printf("File saved successfully.\n");
return 1;
}