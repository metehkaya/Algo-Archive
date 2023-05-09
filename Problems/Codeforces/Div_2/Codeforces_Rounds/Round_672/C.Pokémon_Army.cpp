#include <bits/stdc++.h>
#define maxn 300003
using namespace std;
typedef long long LL;

LL ans;
int T,n,q;
int ar[maxn];
bool bigger[maxn];

void check2(int i) {
	if(bigger[i] && !bigger[i+1])
		ans -= ar[i];
	else if(!bigger[i] && bigger[i+1])
		ans += ar[i];
}

void check1(int i) {
	if(bigger[i] && !bigger[i+1])
		ans += ar[i];
	else if(!bigger[i] && bigger[i+1])
		ans -= ar[i];
}

void input() {
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		if(ar[i] > ar[i-1])
			bigger[i] = true;
		else
			bigger[i] = false;
	}
}

void calc() {
	ans = 0;
	ar[n+1] = 0;
	bigger[n+1] = false;
	for( int i = 1 ; i <= n ; i++ )
		check1(i);
	printf("%lld\n",ans);
}

void solve() {
	for( int qq = 0 , l , r ; qq < q ; qq++ ) {
		scanf("%d%d",&l,&r);
		set<int> s;
		s.insert(l);
		if(l > 1)
			s.insert(l-1);
		if(l < n)
			s.insert(l+1);
		s.insert(r);
		if(r > 1)
			s.insert(r-1);
		if(r < n)
			s.insert(r+1);
		set<int>::iterator it;
		for( it = s.begin() ; it != s.end() ; it++ ) {
			int i = (*it);
			check2(i);
		}
		swap(ar[l],ar[r]);
		for( it = s.begin() ; it != s.end() ; it++ ) {
			int i = (*it);
			if(ar[i] > ar[i-1])
				bigger[i] = true;
			else
				bigger[i] = false;
		}
		for( it = s.begin() ; it != s.end() ; it++ ) {
			int i = (*it);
			check1(i);
		}
		printf("%lld\n",ans);
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		input();
		calc();
		solve();
	}
	return 0;
}
