#include <stdio.h>
#include <time.h>
#include "go.h"
#include "movegen.h"

void print_position( void );

int main( void )
{

	// Initialize the seed:
	seed = time(NULL);

	usint i;

	usint black_wins = 0;
	usint white_wins = 0;
	time_t start,end;
	start = clock();
	
	unsigned long int lp;
	
	for( lp = 0; lp < 1000000; lp++ ) {
		for( i = 0; i < AREA; i++ ) {
			checkbounds(i, SIZE);
			checkbounds(i, -SIZE);
			checkbounds(i, 1);
			checkbounds(i, -1);
		}	
	}

/*
	for( i = 0; i < 10000; i++ ) {

		int sqr;
		
		for( sqr = 0; sqr < AREA; sqr++ ) {
			setbit( pieces, sqr, 0 );
			setbit( colors, sqr, 0 );
		}
		
		black_prisoners = 0;
		white_prisoners = 0;
	
		unsigned char winner = playRandomGame();
		if( winner == 255 ) {
			white_wins++;
		} else {
			black_wins++;
		}

	}
*/
	end = clock();  
	printf("Loop used %f seconds.\n", (difftime(end, start) / CLOCKS_PER_SEC) );
	printf("Black Wins: %d, White Wins: %d \n", black_wins, white_wins);
	
/*
	for( i = 1; ; i++ ) {

		int x, y;

		printf("\nPlease insert x coord: ");
		scanf("%d", &x);	
		printf("Please insert y coord: ");
		scanf("%d", &y);

		// Calculate coordinate from (x,y)
		usint coord = ((y - 1) * SIZE) + x - 1;
		usint color = ( i + 1 ) % 2;

		create_stone( coord, color );

		print_position();
	}
*/

}

void print_position( void ) 
{

	int i;

	printf("\n");
	printf("1.  ");

	for( i = 0; i < AREA; i++ ) {
		
		int bit = getbit(pieces, i);

		if( bit == 0 ) {
			printf(".");
		} else {
			if( getbit(colors, i) == 0 ) {
				printf("#"); // Black
			} else {	
				printf("O"); // White
			}
		}

		if( (i + 1) % SIZE == 0 ) {
			printf("\n");
			int cur = ((i / SIZE) + 2);
			if( cur != (SIZE + 1) ) {			
				printf("%d", cur );
				printf(". ");
				if( cur < 10 ) { printf(" "); }			
			}
		}	
	
	}
	
}



