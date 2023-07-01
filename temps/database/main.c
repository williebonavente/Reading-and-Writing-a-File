/*
Displays all products in the database that satisfy the search
parameters specfied by the program user.
*/

#include <stdio.h>
#include <string.h>

// const macros
#define MIN_STOCK 1111    // minimum stock number
#define MAX_STOCK 9999    // maximum stock number
#define MAX_PRIZE 1000.00 // maximum product price
#define STR_SIZE 80       // number of characters in a string

typedef struct // product structure type
{
    int stock_num; // stock number
    char category_num[STR_SIZE];
    char tech_description[STR_SIZE];
    double price;
} product_t;

typedef struct // search parameter bounds type
{
    int low_stock, high_stock;
    char low_category[STR_SIZE], high_category[STR_SIZE];
    char low_tech_descript[STR_SIZE], high_tech_descript[STR_SIZE];
    double low_price, high_price;
} search_params_t;

search_params_t get_params(void);
void display_match(FILE *databasep, search_params_t params);

// Insert prototypes of functions needed by get_params and display_match
int main(void)
{
    char inv_filename[STR_SIZE]; // name of inventory file
    FILE *inventoryp;            // inventory file pointer
    search_params_t params;      // search parameter bounds

    // Get name of inventory file and open it.
    printf("Enter name of inventory file > ");
    scanf("%s", inv_filename);
    inventoryp = fopen(inv_filename, "rb");

    // Get the search parameters
    params = get_params();

    // Display all products that satisfy the search parameters
    display_match(inventoryp, params);

    return 0;
}

// TODO: CONTINUE...
/*
Prompts the user to enter the search parameters
*/

search_params_t get_params(void)
{
    // body of get_params to be inserted
}

/*
Displays records of all products in the inventory that satisfy search
parameters.

Pre: databasep access a binary file of product_t records that has
     been opened as input file, and params is defined
*/

void display_match(FILE *databasep,        // input - file pointer to binary database file
                   search_params_t params) // input-search parameter bounds
{
    // body of display_match to be inserted here
}

// Insert functions needed by get_params and display_match

/**
 * Displays a lettered menu with the current values of search parameters.
 * Returns the letter user enters. A letter in the range a..h selects
 * a parameter to change; q quits, accepting search parameters shown.
 * Post: first nonwhitespace character entered is returned
 *
 */

char menu_choose(search_params_t params) // input - current search parameter bounds
{
    char choice;

    printf("Select by letter search parameter to set or enter");
    printf("q to \naccept parameters shown.\n\n");
    printf("               Search parameter                           ");
    printf("Current value\n\n");
    printf("[a] Low bound for stock number                       %4d\n", params.low_stock);
    printf("[b] High bound for stock number                      %4d\n", params.high_stock);
    printf("[c] Low bound for category                           %s\n", params.low_category);
    printf("[d] High bound for category                          %s\n", params.high_category);
    printf("[e] Low bound for technical description              %s\n", params.low_tech_descript);
    printf("[f] High bound for technical description             %s\n", params.high_tech_descript);
    printf("[g] Low bound for price                              $%7.2f\n", params.low_price);
    printf("[h] High bound for price                             $%7.2f\n\n", params.high_price);

    printf("Selection > ");
    scanf(" %c", &choice);

    return choice;
}