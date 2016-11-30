// Functions from header file extend.h //
// Libraries
#include <stdio.h>
#include <stdlib.h>


// Define DEBUG code mode
#define DEBUG 1
//
// Declaration of the global variable
int table[3][3];

//  Functions //


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
