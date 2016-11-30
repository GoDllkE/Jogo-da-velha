#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enable personal header loading
#include "extend.h"

// Enable debug code mode
#define DEBUG 1 

// Prototypes
void clean_table();
void print_table();
int check_winner();
int make_move(int player);

/* Global values */
int table[3][3];

/* Control variables */
int player=0x00;
int control=0x00;

int main()
{
    // Cleat terminal //
    system("clear");

    // Creator //
    fprintf(stdout, "\n==> Jogo da velha feito por [ Gustavo Toledo ] \n\n");

    // Clean memory trash //
    clean_table();

    // Quantity of moves
    while(control < 8) {
        /* Add one more by running it */
        control++;

        // Game can run // Set player selection //
        if(player == 0)
            player=1;
        else if(player == 1)
            player=2;
        else
            player=1;

        // Let player do a movement //
        make_move(player);

        // Check if after the movement we have a winner on it //
        if (check_winner() == 1) {
            // Variable //
            char option='s';

            // Message //
            fprintf(stdout, "\n==> The winner is player 1!. Congratulations..");
            fprintf(stdout, "\n==> Play again? (S/n)");
            fprintf(stdout, "\nR: ");
            fscanf(stdin, " %c", &option);
            fflush(stdin);

            if(option == 's' || option == 'S') {
                // Define movement control to 0 //
                control=0x00;

                // Clean game table //
                clean_table();

                // Message user and start it //
                fprintf(stdout, "\n==> Table cleaned, starting game...");
                fprintf(stdout, "\n\n\n\n\n\n\n");
                main();
            }
            else
            fprintf(stdout, "\nBye!\n\n");
        }
        else if (check_winner() == 2) {
            // Variable //
            char option='s';

            // Message //
            fprintf(stdout, "\n==> The winner is player 2!. Congratulations..");
            fprintf(stdout, "\n==> Play again? (S/n)");
            fprintf(stdout, "\nR: ");
            fscanf(stdin, " %c", &option);
            fflush(stdin);

            if(option == 's' || option == 'S') {
                // Define movement control to 0 //
                control=0x00;

                // Clean game table //
                clean_table();

                // Message user and start it //
                fprintf(stdout, "\n==> Table cleaned, starting game...");
                fprintf(stdout, "\n\n\n\n\n\n\n");
                main();
            }
            else
                fprintf(stdout, "\nBye!\n\n");
        } // Else - Continue //
    } // End of while

    // Game full, can't run it //
    // Ask if want to play again
    print_table();
    char option='s';

    fprintf(stdout, "\n\n==> Game table full, no winners... clean it? (S/n)\n");
    fprintf(stdout, "R: ");
    fscanf (stdin, " %c", &option);
    fflush(stdin);

    if(option == 's' || option == 'S') {
        // Define movement control to 0 //
        control=0x00;

        // Clean game table //
        clean_table();

        // Message user and start it //
        fprintf(stdout, "\n==> Table cleaned, starting game...");
        fprintf(stdout, "\n\n\n\n\n\n\n");
        main();
    }
    else {
        fprintf(stdout, "\nBye!\n\n");
        return 0;
    }
    // End of main
}

int make_move(int player)
{
    // variables
    int lat=0x00, lon=0x00;

    // Check player id
    if (!((player >= 1) && (player <= 2))) {
        fprintf(stderr, "==> Player invalido! [%i]", player);
    }

    // Show player simbol type
    char simbol = '-';

    // Set simbol to show
    if (player == 1)
        simbol = 'x';
    else
        simbol = 'o';

    // Show game table //
    print_table();

    // Get location //
    fprintf(stdout, "\n\n\n[Player: %i - jogando com: \'%c\' ]\n ==> Local: ", player, simbol);
    fscanf(stdin, " %i %i", &lat, &lon);
    fflush(stdin);

    // Set movement
    char wait='r';

    if(player == 1) {
        if ((table[lat][lon] != 0) && (table[lat][lon] == 1)) {
            fprintf(stdout, "==> Posicao ja sendo ocupada, escolha outra!\n");
            fprintf(stdout, "\n\n");
            make_move(player);
        }
        else {
            table[lat][lon] = 1;
        }
    }
    else if (player == 2) {
        if ((table[lat][lon] != 0) && (table[lat][lon] == 2)) {
            fprintf(stdout, "==> Posicao ja sendo ocupada, escolha outra! <enter>\n");
            fprintf(stdout, "\n\n");
            make_move(player);
        }
        else {
            table[lat][lon] = 2;
        }
    }
    else
        table[lat][lon] = 0;

}

void clean_table()
{
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if (table[i][j] != 0x00)
                table[i][j] = 0x00;
        }
    }
}

void print_table()
{
    // Game table header
    fprintf(stdout, "-   (0)   (1)   (2)   \n");
    // fprintf(stdout, "________________________\n");
    fprintf(stdout, "------------------");

    for (int i=0; i < 3; i++) {
        fprintf(stdout, "\n");

        // Game table header
        if (i == 0)
            fprintf(stdout, "0)  ");
        else if(i == 1)
            fprintf(stdout, "1)  ");
        else
            fprintf(stdout, "2)  ");

        for(int j=0; j < 3; j++) {
            if (table[i][j] == 1)
                fprintf(stdout, "[X]");
            else if (table[i][j] == 2)
                fprintf(stdout, "[O]");
            else
                fprintf(stdout, "[ ]", &table[i][j]);

            if (j == 2)
                fprintf(stdout, "\n");
            else
                fprintf(stdout, " | ");
        }
    }
}

int check_winner() {
    // Variables //
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

    return player_id;
}
