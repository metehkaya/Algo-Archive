#include <bits/stdc++.h>
#define pb push_back
#define maxn 103
using namespace std;

int T,n;
int ar[maxn];
int lck[maxn];
vector<int> v;

void reset() {
	v.clear();
}

void input() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&lck[i]);
}

void solve() {
	for( int i = 0 ; i < n ; i++ )
		if(!lck[i])
			v.pb(ar[i]);
	sort(v.begin(),v.end());
}

void output() {
	for( int i = 0 , j = v.size()-1 ; i < n ; i++ ) {
		if(lck[i])
			printf("%d ",ar[i]);
		else
			printf("%d ",v[j--]);
	}
	puts("");
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		output();
	}
	return 0;
}
