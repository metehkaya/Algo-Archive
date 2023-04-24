#include <bits/stdc++.h>
#define maxn 200003
using namespace std;
typedef long long LL;

int T,n,m;
LL ar[maxn];
LL sum1[maxn];
LL sum2[maxn];
vector<LL> tree1, tree2;

void reset() {
	tree1.clear();
	tree1.resize(n+1,0);
	tree2.clear();
	tree2.resize(n+1,0);
}

void update( int x , LL add , vector<LL>& tree ) {
	while(x <= n) {
		tree[x] += add;
		x += (x & (-x));
	}
}

LL query( int x , vector<LL>& tree ) {
	LL total = 0;
	while(x) {
		total += tree[x];
		x -= (x & (-x));
	}
	return total;
}

int main() {
	cin >> T;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		reset();
		for( int i = 1 ; i <= n ; i++ )
			scanf("%lld",&ar[i]);
		for( int i = 1 ; i <= n ; i++ ) {
			LL val1 = ar[i];
			LL val2 = i*ar[i];
			if(i % 2 == 0) {
				val1 = -val1;
				val2 = -val2;
			}
			update( i , val1 , tree1 );
			update( i , val2 , tree2 );
		}
		LL ans = 0;
		for( int i = 0 ; i < m ; i++ ) {
			int x,y;
			char s[3];
			scanf("%s%d%d",s,&x,&y);
			if(s[0] == 'U') {
				LL diff1 = y-ar[x];
				LL diff2 = x*diff1;
				if(x % 2 == 0) {
					diff1 = -diff1;
					diff2 = -diff2;
				}
				update( x , diff1 , tree1 );
				update( x , diff2 , tree2 );
				ar[x] = y;
			}
			else {
				LL diff1 = query( y , tree1 ) - query( x-1 , tree1 );
				LL diff2 = query( y , tree2 ) - query( x-1 , tree2 );
				LL total = diff2 - diff1 * (x-1);
				if(x%2 == 0)
					total = -total;
				ans += total;
			}
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;	
}
