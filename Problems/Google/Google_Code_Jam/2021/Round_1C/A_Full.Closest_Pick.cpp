#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pi;

int T,n,k,ans;
int ar[30];

void reset() {
	ans = 0;
}

void output(int tc) {
	printf("Case #%d: %.7lf\n",tc,(double)ans/k);
}

void input() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
}

void solve() {
	sort(ar,ar+n);
	set<pi> mys;
	vector<pi> v;
	for( int i = 1 ; i < n ; i++ )
		if(ar[i-1]+1 <= ar[i]-1)
			mys.insert(pi(ar[i-1]+1,ar[i]-1));
	if(1 < ar[0])
		mys.insert(pi(1,ar[0]-1));
	if(ar[n-1] < k)
		mys.insert(pi(ar[n-1]+1,k));
	set<pi>::iterator sit;
	for( sit = mys.begin() ; sit != mys.end() ; sit++ )
		v.push_back((*sit));
	int m = v.size();
	for( int i = 0 ; i < m ; i++ )
		for( int j = i ; j < m ; j++ ) {
			int sum = 0;
			int leni = v[i].se-v[i].fi+1;
			int lenj = v[j].se-v[j].fi+1;
			if(i == j)
				sum = leni;
			else {
				if(v[i].fi == 1)
					sum += leni;
				else
					sum += (leni+1)/2;
				if(v[j].se == k)
					sum += lenj;
				else
					sum += (lenj+1)/2;
			}
			ans = max(ans,sum);
		}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		output(tc);
	}
	return 0;
}
