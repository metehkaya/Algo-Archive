#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1003
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int T,n;
pii ar[maxn];
int ans[maxn];
int nextMove[maxn][maxn];

int check(int left, int right) {
	if(left == 0 || ar[left].fi.se <= ar[right].fi.fi)
		return true;
	return false;
}

bool f(int cameron, int jamie) {
	int curr = max(cameron, jamie) + 1;
	if( curr == n+1 )
		return true;
	if(nextMove[cameron][jamie] == -2)
		return false;
	nextMove[cameron][jamie] = -2;
	if( check(cameron, curr) && f(curr, jamie) ) {
		nextMove[cameron][jamie] = 0;
		return true;
	}
	if( check(jamie, curr) && f(cameron, curr) ) {
		nextMove[cameron][jamie] = 1;
		return true;
	}
	return false;
}

void output(int tc, bool res) {
	printf("Case #%d: ",tc);
	if(res) {
		ans[ar[1].se] = 0;
		int cameron = 1 , jamie = 0;
		for( int i = 2 ; i <= n ; i++ ) {
			ans[ar[i].se] = nextMove[cameron][jamie];
			if(nextMove[cameron][jamie] == 0)
				cameron = i;
			else
				jamie = i;
		}
		for( int i = 1 ; i <= n ; i++ ) {
			if(ans[i] == 0)
				printf("C");
			else
				printf("J");
		}
	}
	else
		printf("IMPOSSIBLE");
	puts("");
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ ) {
			scanf("%d%d",&ar[i].fi.fi,&ar[i].fi.se);
			ar[i].se = i;
		}
		sort( ar+1 , ar+n+1 );
		memset(nextMove, -1, sizeof(nextMove));
		bool res = f(1,0);
		output(tc,res);
	}
	return 0;
}
