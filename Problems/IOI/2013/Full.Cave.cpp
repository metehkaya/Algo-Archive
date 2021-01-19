#include <bits/stdc++.h>
#include "cave.h"
#define maxn 5000
#define pb push_back
using namespace std;

bool isOpen(int val , int id) {
	return val == -1 || val > id;
}

void exploreCave(int n) {
	int turn[n];
	int doors[n];
	memset(turn,-1,sizeof(turn));
	memset(doors,-1,sizeof(doors));
	int curr[n];
	for( int i = 0 ; i < n ; i++ )
		curr[i] = 0;
	bool openNow, openBefore;
	int leftmost = tryCombination(curr);
	for( int door = 0 ; door < n ; door++ ) {
		openBefore = openNow = isOpen(leftmost,door);
		vector<int> ids;
		for( int i = 0 ; i < n ; i++ )
			if(doors[i] == -1)
				ids.pb(i);
		int l = 0 , r = n-door-1;
		while(l < r) {
			int m = (l+r)>>1;
			for( int i = l ; i <= m ; i++ )
				curr[ids[i]] ^= 1;
			leftmost = tryCombination(curr);
			openNow = isOpen(leftmost,door);
			if(openBefore == openNow)
				l = m+1;
			else
				r = m;
			openBefore = openNow;
		}
		doors[ids[l]] = door;
		if(openNow)
			turn[ids[l]] = curr[ids[l]];
		else {
			turn[ids[l]] = !curr[ids[l]];
			curr[ids[l]] = !curr[ids[l]];
			leftmost = tryCombination(curr);
		}
	}
	answer(turn,doors);
}
