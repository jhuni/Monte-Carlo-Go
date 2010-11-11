#include <stdlib.h>
#include "go.h"
#include "chains.h"

/* This function merely takes a color and then it essentially searches for all stones of that
color and if those stones lack liberties then remove them, that is all. */

void analyze_captures( unsigned char color ) 
{

	usint *safe_squares = calloc(AREA, sizeof(usint));
	usint sqrsize = 0;

	usint i;

	struct chain_info mychain;
	mychain.liberties = calloc(AREA, sizeof(usint));			
	mychain.libcount = 0;
	mychain.stones = calloc(AREA, sizeof(usint));
	mychain.stonecount = 0;

	for( i = 0; i < AREA; i++ ) {

		if( IsPiece(i) && getbit( colors, i) == color && isContained(safe_squares, sqrsize, i) == 0 ) {

			// Calculate the liberties:
			mychain.libcount = 0;
			mychain.stonecount = 1;
			*(mychain.stones + 0) = i;
 			mychain = analyze_chain(mychain, i, color);
			
			if( mychain.libcount == 0 ) {
			
				// Remove piece if liberties are clearly lacking:	
				int lp;
				
				for( lp = 0; lp < mychain.stonecount; lp++ ) {
					clear_square( *(mychain.stones + lp), color );
				}

			} else {

				int lp;
	
				for( lp = 0; lp < mychain.stonecount; lp++ ) {
					*(safe_squares + sqrsize) = *(mychain.stones + lp);
					sqrsize++;
				}

			}

		}

	}

}

struct chain_info analyze_chain( struct chain_info rval, usint i, unsigned char color )
{

			*(dirs + 0) = UP;
			*(dirs + 1) = LEFT;
			*(dirs + 2) = DOWN;
			*(dirs + 3) = RIGHT;
			unsigned char lp;
			
			for( lp = 0; lp < 4; lp++ ) {

				signed short int loc = *(dirs + lp);		

				if( checkbounds(i, loc) == 1 ) {

					usint coord = (i + loc);

					if( IsNotPiece(coord) ) {

						if( isContained( rval.liberties, rval.libcount, coord ) == 0 ) {
							*(rval.liberties + rval.libcount) = coord;
							rval.libcount++;
						}		

					} else if ( getbit(colors, coord) == color ) {
		
						if( isContained( rval.stones, rval.stonecount, coord ) == 0 ) {
							*(rval.stones + rval.stonecount) = coord;
							rval.stonecount++;
							rval = analyze_chain( rval, coord, color );
						}
					}
					
				}

			}

			return rval;

}


