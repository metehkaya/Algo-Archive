#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 2001
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n,m,k,ans;
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
pi ar[maxn*maxn];
int mx[maxn*maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d%d",&a[i],&b[i]);
	for( int i = 1 ; i <= m ; i++ )
		scanf("%d%d",&c[i],&d[i]);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			if(a[i] <= c[j] && b[i] <= d[j])
				ar[++k] = pi(c[j]-a[i]+1,d[j]-b[i]+1);
	if(k == 0) {
		puts("0");
		return 0;
	}
	sort(ar+1,ar+k+1);
	mx[k+1] = 0;
	for( int i = k ; i >= 1 ; i-- )
		mx[i] = max( mx[i+1] , ar[i].se );
	ans = INT_MAX;
	for( int i = 0 ; i <= k ; i++ )
		ans = min( ans , ar[i].fi + mx[i+1] );
	printf("%d\n",ans);
	return 0;
}
