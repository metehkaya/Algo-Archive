#include <bits/stdc++.h>
#include "rail.h"
#define maxn 5000
using namespace std;

void findLocation(int n, int loc0, int loc[], int type[]) {
	loc[0] = loc0;
	type[0] = 1;
	int dist[n];
	if(n > 1) {
		int closest = -1;
		for( int i = 1 ; i < n ; i++ ) {
			dist[i] = getDistance(0,i);
			if(closest == -1 || dist[i] < dist[closest])
				closest = i;
		}
		int locc = loc[closest] = loc0 + dist[closest];
		type[closest] = 2;
		for( int i = 1 ; i < n ; i++ )
			if(i != closest) {
				int dic = getDistance(i,closest);
				if(dist[i] < dic) {
					loc[i] = loc0 + dist[i];
					type[i] = 2;
				}
				else {
					loc[i] = locc - dic;
					type[i] = 1;
				}
			}
	}
}
