// Header file extend.h //
//
//  By: Gustavo Toledo
//  Date: qua nov 30 18:28:22 BRST 2016
//  Version: 1.00.0
//
// Define global variables //
int table[3][3]; // Set global syntax //
int player=0x00;
int control=0x00;

//
// Here, list all functions that going to be used. //
//
void clean_table();
void print_table();
int check_winner();
int make_move(int player);

// End of header //
