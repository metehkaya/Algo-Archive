// Encoder

#include "encoder.h"
#include "encoderlib.h"

int enc[4] = {1,5,25,125};

void encode(int n, int ar[]) {
	if(n <= 32) {
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < 8 ; j++ )
				if(ar[i] & (1<<j))
					send(8*i+j);
	}
	else {
		for( int i = 0 ; i < n ; i++ ) {
			int x = ar[i];
			for( int j = 3 ; j >= 0 ; j-- )
				while(x >= enc[j]) {
					x -= enc[j];
					send(4*i+j);
				}
		}
	}
}

// Decoder

#include "decoder.h"
#include "decoderlib.h"

int dec[4] = {1,5,25,125};

void decode(int n, int m, int x[]) {
	int ar[n];
	for( int i = 0 ; i < n ; i++ )
		ar[i] = 0;
	if(n <= 32) {
		for( int i = 0 ; i < m ; i++ ) {
			int id = x[i] / 8;
			int b = x[i] % 8;
			ar[id] |= (1<<b);
		}
	}
	else {
		for( int i = 0 ; i < m ; i++ ) {
			int id = x[i] / 4;
			int b = x[i] % 4;
			ar[id] += dec[b];
		}
	}
	for( int i = 0 ; i < n ; i++ )
		output(ar[i]);
}
