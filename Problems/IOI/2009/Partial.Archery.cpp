#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200000
#define mod 1000000007
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n,k;
int ar[2*maxn];
int ansLast,ansInit;

void swaps(vector<pi>& vec) {
	for( int i = 0 ; i < n ; i++ )
		if(vec[i].fi > vec[i].se)
			swap(vec[i].fi,vec[i].se);
}

int getHash(vector<pi>& vec) {
	LL val = 0;
	for( int i = 0 ; i < n ; i++ ) {
		val = 2*n*val + vec[i].fi-1;
		val = 2*n*val + vec[i].se-1;
		val %= mod;
	}
	return val;
}

bool check(vector< vector<pi> >& vecs , vector<pi>& vec , int r , vector<int>& vals , int val) {
	for( int i = 0 ; i < r ; i++ )
		if(vals[i] == val) {
			int len = r-i;
			int rem = k-i;
			int add = rem % len;
			vec = vecs[i+add];
			return true;
		}
	return false;
}

void solve(int t) {
	vector<pi> vec;
	vector<int> vals;
	vector< vector<pi> > vecs;
	for( int i = 0 ; i < n ; i++ )
		vec.pb(pi(0,0));
	vec[t].fi = ar[0];
	for( int i = 1 , idx = 0 ; i < 2*n ; i++ ) {
		if(vec[idx].fi == 0)
			vec[idx].fi = ar[i];
		else
			vec[idx++].se = ar[i];
	}
	swaps(vec);
	vecs.pb(vec);
	vals.pb(getHash(vec));
	for( int r = 1 ; r <= k ; r++ ) {
		vector<pi> last = vec;
		for( int i = 1 ; i < n ; i++ ) {
			vec[i-1].fi = min(last[i].fi,last[i].se);
			vec[i].se = max(last[i].fi,last[i].se);
		}
		vec[0].se = min(last[0].fi,last[0].se);
		vec[n-1].fi = max(last[0].fi,last[0].se);
		swaps(vec);
		int val = getHash(vec);
		if(check(vecs,vec,r,vals,val))
			break;
		vecs.pb(vec);
		vals.pb(getHash(vec));
	}
	for( int i = 0 ; i < n ; i++ )
		if(vec[i].fi == ar[0] || vec[i].se == ar[0]) {
			if(i <= ansLast) {
				ansLast = i;
				ansInit = t;
			}
			break;
		}
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < 2*n ; i++ )
		scanf("%d",&ar[i]);
	ansLast = n;
	for( int t = 0 ; t < n ; t++ )
		solve(t);
	printf("%d\n",ansInit+1);
	return 0;
}
