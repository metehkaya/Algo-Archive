#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T;
vector<pi> moves;

void precalc() {
	moves.pb(pi(8,8));
	moves.pb(pi(7,7));
	moves.pb(pi(6,8));
	moves.pb(pi(1,3));
	moves.pb(pi(2,4));
	moves.pb(pi(1,5));
	moves.pb(pi(4,8));
	moves.pb(pi(3,7));
	moves.pb(pi(2,8));
	moves.pb(pi(1,7));
	int sz = (int) moves.size();
	for( int i = sz-1 ; i >= 1 ; i-- )
		moves.pb( pi( moves[i].se , moves[i].fi ) );
}

int main() {
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		vector<pi> premoves;
		int r,c;
		scanf("%d%d",&r,&c);
		if(r != 1 || c != 1) {
			if(r != c) {
				r = c = (r+c)/2;
				premoves.pb(pi(r,c));
			}
			premoves.pb(pi(1,1));
		}
		int step1 = premoves.size();
		int step2 = moves.size();
		printf("%d\n",step1+step2);
		for( int i = 0 ; i < step1 ; i++ )
			printf("%d %d\n", premoves[i].fi, premoves[i].se);
		for( int i = 0 ; i < step2 ; i++ )
			printf("%d %d\n", moves[i].fi, moves[i].se);
	}
	return 0;
}
