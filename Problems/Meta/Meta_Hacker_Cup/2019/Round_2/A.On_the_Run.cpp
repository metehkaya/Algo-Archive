#include <bits/stdc++.h>
using namespace std;

int T,n,m,k;
int x[3],y[3];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

char solve() {
	if(k == 1)
		return 'N';
	int d1 = abs(x[1]-x[0]) + abs(y[1]-y[0]);
	int d2 = abs(x[2]-x[0]) + abs(y[2]-y[0]);
	if(d1%2 == 0 && d2%2 == 0)
		return 'Y';
	return 'N';
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&n,&m,&k);
		for( int i = 0 ; i <= k ; i++ )
			scanf("%d%d",&x[i],&y[i]);
		printf("Case #%d: %c\n",tc,solve());
	}
	return 0;
}
