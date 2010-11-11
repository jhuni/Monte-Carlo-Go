#include <stdlib.h>
#include "go.h"
#include "chains.h"

unsigned char checkbounds( usint i, signed short int loc ) 
{

	if( loc == 1 ) {
		if ( (i + 1) % SIZE != 0 ) {
			return 1;
		}		
	} else if( loc == -1 ) {
		if ( (i + 1) % SIZE != 1 ) {
			return 1;
		}
	} else if( loc < 0 ) {
		if( (i + loc) > 0 ) {
			return 1;
		}
	} else {
		if( (i + loc) < AREA ) {
			return 1;
		}
	}

	return 0;

}

void clear_square( usint square, unsigned char color ) 
{

	setbit( pieces, square, 0 );
	setbit( pieces, square, 0 );

	if( color == 1 ) {
		black_prisoners++;
	} else {
		white_prisoners++;
	}

}

void create_stone( usint coord, unsigned char color ) 
{

	setbit( pieces, coord, 1 );
	setbit( colors, coord, color );

	if( color == 0 ) {
		analyze_captures(1);
	} else {
		analyze_captures(0);
	}

	analyze_captures( color );

}

unsigned char isContained( usint *mycont, usint mysize, usint mysub )
{

	int i;
	
	for( i = 0; i < mysize; i++ ) {
		if( *(mycont + i) == mysub ) {
			return 1;
		}
	}
	
	return 0;

}

int getbit(char *set, int number)
{
        set += number / 8;
        return (*set & (1 << (number % 8))) != 0;       /* 0 or 1       */
}

int setbit(char *set, int number, int value)
{
        set += number / 8;
        if (value)
                *set |= 1 << (number % 8);              /* set bit      */
        else    *set &= ~(1 << (number % 8));           /* clear bit    */
}


/*

SetTrue(x, n)
x |= (1 >> n)

SetFalse(x, n)
x &= ~(1 >> n)

Flip(x, n)
x ^= (1 >> n)

BitTest(x, n)
if( (x & (1 >> x)) > 0 )

*/
