#include <bits/stdc++.h>
#define maxk 19
#define maxn 300002
#define maxs 1000001
#define pb push_back
using namespace std;
typedef long long LL;

int n;
LL ans;
int rev[maxn];
int mx[maxn][maxk];
vector<int> v[maxs];

void read() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&mx[i][0]);
}

void preCalc() {
	for( int i = 2 ; i < maxn ; i *= 2 )
		rev[i] = rev[i/2] + 1;
	for( int i = 3 ; i < maxn ; i++ )
		if(!rev[i])
			rev[i] = rev[i-1];
	for( int i = 1 ; i <= n ; i++ )
		v[mx[i][0]].pb(i);
	for( int k = 1 ; (1<<k) <= n ; k++ )
		for( int i = 1 ; i+(1<<k)-1 <= n ; i++ )
			mx[i][k] = max( mx[i][k-1] , mx[i+(1<<(k-1))][k-1] );
}

int check(int left , int right) {
	int len = right-left+1;
	int k = rev[len];
	return max( mx[left][k] , mx[right-(1<<k)+1][k] );
}

void solve() {
	for( int val = 1 ; val < maxs ; val++ ) {
		int sz = v[val].size();
		for( int l = 0 , r = 0 ; l < sz ; l = r ) {
			while(r < sz && check( v[val][l] , v[val][r] ) <= val)
				r++;
			int cnt = r-l;
			ans += (LL) cnt*(cnt-1);
		}
	}
	printf("%lld\n",ans);
}

int main() {
	read();
	preCalc();
	solve();
	return 0;
}
