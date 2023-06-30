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
    search_params_t params;        // search parameter bounds

    // Get name of inventory file and open it.
    printf("Enter name of inventory file > ");
    scanf("%s", inv_filename);
    inventoryp = fopen(inv_filename, "rb");

    // Get the search parameters
    params = get_params();

    // Display all products that satisfy the search paramters
    display_match(inventoryp, params);

    return 0;
}

// TODO: CONTINUE...