#ifndef CHAINS_H
#define CHAINS_H

/* This is used to describe any stone chain */

struct chain_info {

	usint *liberties;
	usint libcount;
	usint *stones;
	usint stonecount;

};

// Functions:
void analyze_captures( unsigned char color );
struct chain_info analyze_chain( struct chain_info rval, usint i, unsigned char color );

#endif
