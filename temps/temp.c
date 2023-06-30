/*
Makes backup file. Repeatedly prompts for the name of a file to
backup up until a name is provided that corresponds to an available
file. Then it prompts for the name of the backup file and creates
the file copy.
*/

#include <stdio.h>
#include <stdlib.h>

#define STRSIZE 80

int main(void)
{

    char in_name[STRSIZE], // string giving names
        out_name[STRSIZE]; // of input and backup files

    FILE *inp, // file pointers for input and
        *out;  // backup files

    char ch; // one character of input file

    // Get the name of the file to back up and open the file for input
    printf("Enter name of file you want to back up > ");
    for (scanf("%s", in_name); (inp = fopen(in_name, "r")) == NULL; scanf("%s", in_name))
    {
        printf("Cannot open %s for input\n", in_name);
        printf("Re-enter file name > ");
    }

    // Get name to use for backup file and open file for ouput
    printf("Enter name for backup copy > ");
    for (scanf("%s", out_name); (out = fopen(out_name, "w")) == NULL; scanf("%s", out_name))
    {
        printf("Cannot open %s for output\n", out_name);
        printf("Re-enter file name > ");
    }

    // Make backup copy one character at a time

    for (ch = getc(inp); ch != EOF; ch = getc(inp))
    {
        putc(ch, out);
    }

    // Closing the file and notify the user of backup completion
    fclose(inp);
    fclose(out);

    printf("Copied %s to %s.\n", in_name, out_name);
    return 0;
}