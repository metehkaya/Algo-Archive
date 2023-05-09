#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100000
using namespace std;
typedef pair<int,int> pi;

int T,n,m;
int ar[maxn];
set<int> s;
multiset<int> diffs;

void input() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&ar[i]);
		s.insert(ar[i]);
	}
}

void sol() {
	if(n <= 2)
		puts("0");
	else {
		int mn = *(s.begin());
		int mx = *(s.rbegin());
		int mxDiff = *(diffs.rbegin());
		printf("%d\n",mx-mn-mxDiff);
	}
}

pi getDiffs(int x) {
	set<int>::iterator it;
	int l = -1 , h = -1;
	if(n) {
		if(x < *(s.rbegin())) {
			it = s.upper_bound(x);
			h = (*it)-x;
		}
		if(x > *(s.begin())) {
			it = s.lower_bound(x);
			it--;
			l = x-(*it);
		}
	}
	return pi(l,h);
}

void solve() {
	sort(ar,ar+n);
	for( int i = 1 ; i < n ; i++ )
		diffs.insert(ar[i]-ar[i-1]);
	sol();
	for( int i = 0 , t,x ; i < m ; i++ ) {
		scanf("%d%d",&t,&x);
		set<int>::iterator it;
		multiset<int>::iterator mit;
		if(t == 0) {
			s.erase(x);
			n--;
			pi p = getDiffs(x);
			int l = p.fi , h = p.se;
			if(l != -1 && h != -1) {
				mit = diffs.find(l);
				diffs.erase(mit);
				mit = diffs.find(h);
				diffs.erase(mit);
				diffs.insert(l+h);
			}
			else if(l != -1) {
				mit = diffs.find(l);
				diffs.erase(mit);
			}
			else if(h != -1) {
				mit = diffs.find(h);
				diffs.erase(mit);
			}
		}
		if(t == 1) {
			pi p = getDiffs(x);
			int l = p.fi , h = p.se;
			if(l != -1 && h != -1) {
				mit = diffs.find(l+h);
				diffs.erase(mit);
				diffs.insert(l);
				diffs.insert(h);
			}
			else if(l != -1)
				diffs.insert(l);
			else if(h != -1)
				diffs.insert(h);
			n++;
			s.insert(x);
		}
		sol();
	}
}

int main() {
	input();
	solve();
	return 0;
}
