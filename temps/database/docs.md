# Case Study: Database Inquiry  

## Problem

Periphs Plus is a mail-order computer supply company that maintains its inventory
as a  computer file in order to facilitate answering questions regarding that database.
Some questions might be:

- What printer stands that cost less than `$100` are available?
- What product has the code 5241?
- What types of data cartridges are available?

These questions and others can be answered if we know the correct way to ask them.

## Analysis

A database inquiry program has two phases: Setting the search parameters and searching for records that satisfy the parameters.
In our program, we will assumed that all the structure components can be involved in the search. The program user must enter low and
high bounds for each field of interest. Let's illustrate how we might set the search parameters to answer the question, What modems that
cost less that `$200` are available?

&tab; Assuming that the price of any Periphs Plus product does not exceed `$`1000`, we can use the following menu-driven dialogue to set
the search parameters.

``` Menu-Driven Dialogue

Select by letter a search parameter to set, or enter q to accept parameter shown.

            Search Parameter                        Current Value
    [a]  Low bound for stock number                     1111
    [b]  High bound for stock number                    9999
    [c]  Low bound for category                         aaaa
    [d]  High bound for category                        zzzz
    [e]  Low bound for technical description            aaaa
    [f]  High bound for technical description           zzzz
    [g]  Low bound for price                            $    0.00
    [h]  High bound for price                           $1.000.00

    Selection > c
    New low bound for category > modem


Select by letter a search parameter to set, or enter q to accept parameter shown.

            Search Parameter                        Current Value
    [a]  Low bound for stock number                     1111
    [b]  High bound for stock number                    9999
    [c]  Low bound for category                         aaaa
    [d]  High bound for category                        zzzz
    [e]  Low bound for technical description            aaaa
    [f]  High bound for technical description           zzzz
    [g]  Low bound for price                            $    0.00
    [h]  High bound for price                           $1.000.00

    Selection > d
    New high bound for category > modem

Select by letter a search parameter to set, or enter q to accept parameter shown.

            Search Parameter                        Current Value
    [a]  Low bound for stock number                     1111
    [b]  High bound for stock number                    9999
    [c]  Low bound for category                         aaaa
    [d]  High bound for category                        zzzz
    [e]  Low bound for technical description            aaaa
    [f]  High bound for technical description           zzzz
    [g]  Low bound for price                            $    0.00
    [h]  High bound for price                           $1.000.00

    Selection > h
    New low bound for category > 199.99

Select by letter a search parameter to set, or enter q to accept parameter shown.

            Search Parameter                        Current Value
    [a]  Low bound for stock number                     1111
    [b]  High bound for stock number                    9999
    [c]  Low bound for category                         aaaa
    [d]  High bound for category                        zzzz
    [e]  Low bound for technical description            aaaa
    [f]  High bound for technical description           zzzz
    [g]  Low bound for price                            $    0.00
    [h]  High bound for price                           $1.000.00

    Selection > q
```

## Data Requirements

### Problem Inputs

`search_param_t params` // search parameter bounds
`char inv_filename[STR_SIZ]` // name of inventory file

## Problem Outputs

All products that satisfy the search.

## Design

### Initial Algorithm

1. Open inventory file.
2. Get search parameters.
3. Display all products that satisfy the search parameters

### DESIGN OF THE FUNCTION SUBPROGRAMS

Function `get_params` must first initialize the search parameters to allow the widest search possible and then
let the user change some parameters to narrow the search.

Local Variables for `get_params`

`search_params_t params;` `// structure whose components must be defined
``char choice;` `// user's response to menu`
