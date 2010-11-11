#ifndef GO_H
#define GO_H

// Essential includes:
#define SIZE 5
#define AREA (SIZE * SIZE)
#define BITCOUNT ( AREA + 7 ) / 8
#define MIDPOINT (SIZE / 2) + 1

typedef unsigned short int usint;

/*
For pieces 0 means there is no piece, 1 means there is.
For colors 0 means there is a white piece and 1 means there is a black piece.
*/

char colors[BITCOUNT];
char pieces[BITCOUNT];

/* 
This is the directions for a user to the board.
*/

#define UP -SIZE;
#define LEFT -1;
#define DOWN SIZE;
#define RIGHT 1;

/* This initializes the directions */

signed char dirs[3];

/*
Macros for conditions
*/

#define IsPiece(coord) \
getbit( pieces, coord ) != 0

#define IsNotPiece(coord) \
getbit( pieces, coord ) == 0

/* 
Store the amount of prisoners for the points at the end of the game.
*/

usint black_prisoners;
usint white_prisoners;

unsigned char checkbounds( usint i, signed short int loc );
void clear_square( usint square, unsigned char color );
void create_stone( usint coord, unsigned char color );
unsigned char isContained( usint *mycont, usint mysize, usint mysub );
int getbit(char *set, int number);
int setbit(char *set, int number, int value);

#endif
