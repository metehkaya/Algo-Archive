#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200003
#define mod 998244353
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int n,m;
int d[maxn];
int sum[maxn];
int ans[maxn];
vector<pii> query;

int pw(int x , int y) {
	if(y == 0)
		return 1;
	LL mult = pw(x,y/2);
	mult = mult*mult % mod;
	if(y&1)
		mult = mult*x % mod;
	return mult;
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	for( int i = 1 ; i <= n ; i++ )
		sum[i] = (sum[i-1] + d[i]) % mod;
	for( int i = 0 , a,b ; i < m ; i++ ) {
		scanf("%d%d",&a,&b);
		query.pb( pii( pi( b,a ) , i ) );
	}
	sort(query.begin(),query.end());
	for( int i = m-1 , j = n ; i >= 0 ; i-- ) {
		while(j && query[i].fi.fi <= d[j])
			j--;
		int k = n-j;
		int a = query[i].fi.se;
		int id = query[i].se;
		if(k < a)
			ans[id] = 0;
		else {
			LL val1 = sum[j];
			val1 = val1 * (k-a+1) % mod * pw(k+1,mod-2) % mod;
			LL val2 = (sum[n] - sum[j] + mod) % mod;
			val2 = val2 * (k-a) % mod * pw(k,mod-2) % mod;
			ans[id] = (val1+val2) % mod;
		}
	}
	for( int i = 0 ; i < m ; i++ )
		printf("%d\n",ans[i]);
	return 0;
}
