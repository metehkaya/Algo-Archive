#include <bits/stdc++.h>
#define maxn 1000
#define pb push_back
using namespace std;

int T,n;
int ar[maxn];
bool mark[maxn];

int gcd(int x , int y) {
	if(y == 0)
		return x;
	return gcd(y,x%y);
}

void reset() {
	for( int i = 0 ; i < n ; i++ )
		mark[i] = false;
}

void input() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
}

void solve() {
	sort(ar,ar+n);
	mark[n-1] = true;
	printf("%d ",ar[n-1]);
	int g = ar[n-1];
	for( int k = 1 ; k < n ; k++ ) {
		int best = INT_MIN , idx = -1;
		for( int i = 0 ; i < n ; i++ )
			if(!mark[i]) {
				int gx = gcd(g,ar[i]);
				if(gx > best) {
					best = gx;
					idx = i;
				}
			}
		printf("%d ",ar[idx]);
		mark[idx] = true;
		g = best;
	}
	puts("");
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
	}
	return 0;
}
