#include <bits/stdc++.h>
#include "artclass.h"
using namespace std;

const int HIGHDIFF_DIFF = 20;
const int HIGHDIFF_LIMIT = 2000;
const double GREEN_RATIO = 0.6;
const int GREEN_LOW_GREEN = 100;
const int GREEN_GREEN_RED_DIFF = 50;
const int GREEN_GREEN_BLUE_DIFF = 50;

int style(int n, int m, int r[500][500], int g[500][500], int b[500][500]) {
	int gcnt = 0 , highdiff = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ ) {
			if(j+1 < m)
				if(abs(r[i][j]-r[i][j+1]) >= HIGHDIFF_DIFF)
					if(abs(g[i][j]-g[i][j+1]) >= HIGHDIFF_DIFF)
						if(abs(b[i][j]-b[i][j+1]) >= HIGHDIFF_DIFF)
							highdiff++;
			if(i+1 < n)
				if(abs(r[i][j]-r[i+1][j]) >= HIGHDIFF_DIFF)
					if(abs(g[i][j]-g[i+1][j]) >= HIGHDIFF_DIFF)
						if(abs(b[i][j]-b[i+1][j]) >= HIGHDIFF_DIFF)
							highdiff++;
			if(g[i][j] >= GREEN_LOW_GREEN)
				if(g[i][j]-b[i][j] >= GREEN_GREEN_BLUE_DIFF)
					if(g[i][j]-r[i][j] >= GREEN_GREEN_RED_DIFF)
						gcnt++;
			}
	int ans;
	if(gcnt >= n*m*GREEN_RATIO)
		ans = 2;
	else if(highdiff <= HIGHDIFF_LIMIT)
		ans = 1;
	else
		ans = 4;
	return ans = 1;
}
