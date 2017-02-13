// Functions from header file extend.h //
// Libraries
#include <stdio.h>
#include <stdlib.h>

// Include header file //
#include "extend.h"
#include "colors.h"

// Define DEBUG code mode //
#define DEBUG 1

// Declaration of the global variables //
// The game table
int table[3][3];

/*******************  Functions ********************/

/*
 * Function to made a movement on game
 * Status: READY
*/
int make_move(int player)
{
    // Internal variables //
    int lat=0x00, lon=0x00;

    // Check player id //
    if (!(player >= 1) && (player <= 2)) {
        fprintf(stderr, "==> Player invalido!\n", player);
        return 0;
        if (DEBUG)
            fprintf(stderr, "=> Player_id: [%d]", player);
    }

    // Show player simbol type //
    char simbol = '-';

    // Set player simbol to show //
    if (player == 1)
        simbol = 'x';
    else
        simbol = 'o';

    // Show game table //
    print_table();

    // Get location //
    fprintf(stdout, "\n\n\n[Player: %i - joganco com: \'$c\' ]");
    fprintf(stdout, "\n==> Local: ");
    fscanf(stdin, " %i %i", &lat, &lon);
    fflush(stdin);

    // Set movement //
    char wait='r';

    if (player == 1) {
        if (table[lat][lon] != 0) {
            fprintf(stderr, "==> Posicao ja ocupada! escolha outra..\n");
            fprintf(stdout,"\n\n");
            make_move(player);
        }
        else
            table[lat][lon] = 1;
    }
    else if (player == 2) {
        if (table[lat][lon] != 0) {
            fprintf(stderr, "==> Posicao ja ocupada! escolha outra..\n");
            fprintf(stdout,"\n\n");
            make_move(player);
        }
        else
            table[lat][lon] = 2;
    }
    else {
        table[lat][lon] = 0;
    }
}


/*
 * Function to clean game table
 * Status: READY
*/
void clean_table()
{
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (table[i][j] != 0x00)
                table[i][j] = 0x00;
        }
    }
}


/*
 * Function to show the game table on terminal
 * Status: READY
*/
void print_table()
{
    // Game table header //
    fprintf(stdout, "-   (0)   (1)   (2)   \n");
    fprintf(stdout, "------------------");

    for (int i=0; i < 3; i++) {
        fprintf(stdout, "\n");

        // Game line header //
        if (i == 0)
            fprintf(stdout, "0)  ");
        else if(i == 1)
            fprintf(stdout, "1)  ");
        else
            fprintf(stdout, "2)  ");

        // Game table content //
        for(int j=0; j < 3; j++) {
            if (table[i][j] == 1)
                fprintf(stdout, "[X]");
            else if (table[i][j] == 2)
                fprintf(stdout, "[O]");
            else
                fprintf(stdout, "[ ]", &table[i][j]);

            // Special characters for game table design //
            if (j == 2)
                fprintf(stdout, "\n");
            else
                fprintf(stdout, " | ");
        }
    }
}


/*
 * Function to check player winner
 * Status: READY
*/
int check_winner() {
    // Local variable //
    int player_id=0x00;

    // Horizontal checkout //
    for (int i=0; i < 3; i++) {
        if((table[i][0] == table[i][1]) && (table[i][1] == table[i][2])) {
            player_id = table[i][0];
            return player_id;
        }
    }

    // Vertical checkout //
    for (int i=0; i < 3; i++) {
        if((table[0][i] == table[1][i]) && (table[1][i] == table[2][i])) {
            player_id = table[0][i];
            return player_id;
        }
    }

    // Others checkouts //
    if ((table[0][0] == table[1][1]) && (table[1][1] == table[2][2]))
        player_id = table[0][0];
    else if ((table[0][2] == table[1][1]) && (table[1][1] == table[2][0]))
        player_id = table[0][2];

    // Return player winner id //
    return player_id;
}
