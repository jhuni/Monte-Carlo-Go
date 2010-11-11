#ifndef MOVEGEN_H
#define MOVEGEN_H

unsigned long int seed;

struct moveset {

	usint *moves;
	usint movecount;

};

// Functions:
unsigned char playRandomGame( void );
void setupPossibleMoves( struct moveset *mv, unsigned char color );
usint make_move( usint *moves, usint movecount );
unsigned char validate_move( usint i, unsigned char color );

#endif
