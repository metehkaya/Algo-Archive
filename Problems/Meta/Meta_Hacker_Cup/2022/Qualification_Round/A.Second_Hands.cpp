#include <bits/stdc++.h>
using namespace std;

int T,n,k;
map<int,int> cnt;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	cnt.clear();
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&n,&k);
		bool ok = ((2*k) >= n);
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			if(++cnt[x] > 2)
				ok = false;
		}
		string ans = (ok) ? "YES" : "NO";
		printf("Case #%d: %s\n",tc,ans.c_str());
	}
	return 0;
}
