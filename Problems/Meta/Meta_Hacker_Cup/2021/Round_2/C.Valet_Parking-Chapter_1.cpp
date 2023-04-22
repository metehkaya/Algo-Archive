#include <bits/stdc++.h>
#define pb push_back
#define maxn 2000003
using namespace std;

int T,n,m,k,ans;
int cnt[maxn];
vector<string> ar;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	ans = 0;
	ar.clear();
	ar.pb("");
}

void input() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 1 ; i <= n ; i++ ) {
		string s;
		cin >> s;
		ar.pb(s);
	}
}

void solve() {
	for( int i = 0 ; i < m ; i++ )
		ans += (ar[k][i] == 'X');
	for( int i = 0 ; i < m ; i++ )
		cnt[i] = 0;
	for( int i = 1 ; i <= k ; i++ )
		for( int j = 0 ; j < m ; j++ )
			cnt[j] += (ar[i][j] == 'X');
	for( int i = 1 ; i <= n-k+1 ; i++ ) {
		int res = 0;
		for( int j = 0 ; j < m ; j++ ) {
			if(k+i <= n)
				cnt[j] += (ar[k+i][j] == 'X');
			if(cnt[j] >= k || (k+i <= n && ar[k+i][j] == 'X'))
				res++;
		}
		ans = min(ans,res+i);
	}
	for( int i = 0 ; i < m ; i++ )
		cnt[i] = 0;
	for( int i = k ; i <= n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			cnt[j] += (ar[i][j] == 'X');
	for( int i = 1 ; i <= k ; i++ ) {
		int res = 0;
		for( int j = 0 ; j < m ; j++ ) {
			if(k-i >= 1)
				cnt[j] += (ar[k-i][j] == 'X');
			if(cnt[j] >= (n-k+1) || (k-i >= 1 && ar[k-i][j] == 'X'))
				res++;
		}
		ans = min(ans,res+i);
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
