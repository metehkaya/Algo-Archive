#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200003
using namespace std;
typedef pair<int,int> pi;

int n,k;
int lvl[maxn];
int depth[maxn];

pi ar[maxn];
set<int> myset;

bool comp2(pi a, pi b) {
	return a.se < b.se;
}

bool comp1(pi a, pi b) {
	if(a.fi != b.fi)
		return a.fi < b.fi;
	return a.se > b.se;
}

void input() {
	scanf("%d",&n);
	for( int i = 1 , val; i <= n ; i++ ) {
		scanf("%d",&val);
		ar[i] = pi(val, i);
	}
}

void precalc() {
	sort(ar+1, ar+n+1, comp1);
	for( int i = 1 ; i <= n ; i++ )
		ar[i].fi = i;
	sort(ar+1, ar+n+1, comp2);
}

void split(int id) {
	set<int>::iterator it = myset.lower_bound(ar[id].fi);
	int val = (*it);
	myset.insert(ar[id].fi);
	lvl[id] = depth[val] + 1;
	depth[ar[id].fi] = depth[val] = lvl[id];
}

void solve() {
	memset(depth, -1, sizeof(depth));
	depth[n] = 0;
	myset.insert(n);
	for( int i = 1 ; i <= n ; i++ )
		split(i);
}

void output() {
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ", lvl[i]);
}

int main() {
	input();
	precalc();
	solve();
	output();
	return 0;
}
