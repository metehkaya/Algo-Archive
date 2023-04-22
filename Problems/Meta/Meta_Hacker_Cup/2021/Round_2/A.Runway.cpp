#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define maxn 1000003
using namespace std;
typedef pair<int,int> pi;

int T,n,m,ans;
int ar[2*maxn];
int curr[maxn];
int used[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void input() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < m ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 0 ; j < m ; j++ )
			scanf("%d",&ar[i*m+j]);
}

void solve() {
	ans = 0;
	for( int i = 0 ; i < m ; i++ )
		curr[i] = ar[i] , used[i] = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		map<int,vector<pi> > mp;
		for( int j = 0 ; j < m ; j++ )
			mp[curr[j]].pb(pi(used[j],j));
		map<int,vector<pi> >::iterator it;
		for( it = mp.begin() ; it != mp.end() ; it++ )
			sort(it->se.begin(),it->se.end());
		vector<int> newvals;
		for( int j = 0 ; j < m ; j++ ) {
			int x = ar[i*m+j];
			it = mp.find(x);
			if(it != mp.end() && !(it->se.empty()))
				it->se.pop_back();
			else
				newvals.pb(x);
		}
		int cnt = 0;
		for( it = mp.begin() ; it != mp.end() ; it++ ) {
			vector<pi> v = it->se;
			int sz = v.size();
			for( int k = 0 ; k < sz ; k++ ) {
				pi p = v[k];
				int idx = p.se;
				curr[idx] = newvals[cnt++];
				if(used[idx])
					ans++;
				else
					used[idx] = true;
			}
		}
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		input();
		solve();
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
