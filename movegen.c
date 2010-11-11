#include <stdlib.h>
#include "go.h"
#include "movegen.h"
#include "chains.h"

unsigned char playRandomGame( void ) 
{
	usint i;

	struct moveset mv;
	mv.moves = calloc(AREA, sizeof(usint));
	mv.movecount = 0;

	for( i = 0; ; i++ ) {

		int move;
		unsigned char color = i % 2;
	
		setupPossibleMoves( &mv, color );

		if( mv.movecount == 0 ) {
			if( i == 0 ) { 
				color++; 
			} else { 
				color--; 
			}
			return color;
		}

		move = make_move( mv.moves, mv.movecount );
		create_stone( move, color );
	}

}

void setupPossibleMoves( struct moveset *mv, unsigned char color ) 
{

	usint i;
	(*mv).movecount = 0;
	
	for( i = 0; i < AREA; i++ ) {

		if( IsNotPiece(i) && validate_move(i, color) != 0 ) {
			*(   (*mv).moves + (*mv).movecount   ) = i;
			(*mv).movecount++;
		}

	}

}

usint make_move( usint *moves, usint movecount ) 
{

	seed += 1;	

	srand ( seed );
	usint move = rand() % movecount;
	usint rval = *(moves + move);
	return( rval );
	
}

unsigned char validate_move( usint i, unsigned char color ) 
{

	struct chain_info mychain;
	mychain.liberties = calloc(AREA, sizeof(usint));			
	mychain.libcount = 0;
	mychain.stones = calloc(AREA, sizeof(usint));
	mychain.stonecount = 1;

	setbit( pieces, i, 1 );
	setbit( colors, i, color );
	mychain = analyze_chain( mychain, i, color );
	setbit( pieces, i, 0 );
	setbit( colors, i, 0 );	

	if( mychain.libcount == 0 ) {
		return 0;
	} else {
		return 1;
	}

}


