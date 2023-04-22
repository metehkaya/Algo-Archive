#include <bits/stdc++.h>
#define maxn 500003
#define pb push_back
using namespace std;

int T,n,k;
int to[maxn];
int dest[maxn];
string ans;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void input() {
	scanf("%d%d",&n,&k);
	for( int i = 1 , val ; i <= n ; i++ ) {
		scanf("%d",&val);
		to[val] = i;
	}
	for( int i = 1 , val ; i <= n ; i++ ) {
		scanf("%d",&val);
		val = to[val];
		dest[i-1] = val;
	}
}

void solve() {
	if(n == 2) {
		if(dest[0] == 1 && dest[1] == 2 && k%2 == 0)
			ans = "YES";
		else if(dest[0] == 2 && dest[1] == 1 && k%2 == 1)
			ans = "YES";
		else
			ans = "NO";
	}
	else {
		int idx = -1;
		for( int i = 0 ; i < n ; i++ )
			if(dest[i] == 1)
				idx = i;
		ans = "YES";
		for( int i = 1 ; i <= n ; i++ )
			if(dest[(idx+i-1)%n] != i) {
				ans = "NO";
				return;
			}
		if(idx == 0 && k == 1)
			ans = "NO";
		if(idx != 0 && k == 0)
			ans = "NO";
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		input();
		solve();
		printf("Case #%d: %s\n",tc,ans.c_str());
	}
	return 0;
}
