#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 4000
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int N,n,ans;
int a[maxn];
int mx[maxn][maxn];
vector<pi> b;
set<int> myset;

int get(int l , int r , int p , LL v) {
	LL v1 = p-l;
	LL v2 = r-p;
	return (v * ((v1*v2) % mod)) % mod;
}

int main() {
	scanf("%d",&n);
	if(n > 4000)
		exit(0);
	for( int i = 0 ; i < n ; i++ )
		scanf( "%d" , &a[i] );
	for( int i = 0 ; i < n ; i++ ) {
		mx[i][i] = a[i];
		for( int j = i + 1 ; j < n ; j++ )
			mx[i][j] = max(mx[i][j-1],a[j]);
	}
	for( int k = 0 ; k <= n - 1 ; k++ )
		for( int i = 0 ; i <= n - k - 1 ; i++ )
			b.pb(pi(mx[i][i+k],N++));
	set<int>::iterator it,it2;
	sort(b.begin(),b.end());
	for( int i = N-1 , l,r ; i >= 0 ; i-- ) {
		it = myset.lower_bound(b[i].se);
		if(it == myset.begin() && it == myset.end()) {
			l = -1;
			r = N;
		}
		else if(it == myset.end()) {
			it2 = it;
			it2--;
			l = (*it2);
			r = N;
		}
		else if(it == myset.begin()) {
			l = -1;
			r = (*it);
		}
		else {
			it2 = it;
			it2--;
			l = (*it2);
			r = (*it);
		}
		ans = (ans + get(l,r,b[i].se,b[i].fi)) % mod;
		myset.insert(b[i].se);
	}
	printf("%d\n",ans);
	return 0;
}
