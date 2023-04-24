#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

int T,n,d,ans;
int ar[maxn];
multiset<int> myset;

void input() {
	scanf("%d%d",&n,&d);
	for( int i = 0 ; i < n ; i++ )	
		scanf("%d",&ar[i]);
}

int f( int mn , int mx ) {
	if(mx-mn >= 2*d)
		return 0;
	multiset<int>::iterator it,beg,last;
	beg = myset.begin();
	it = beg;
	it++;
	int res = max(0,d-((*it)-mn));
	int val = (*it);
	it++;
	last = myset.end();
	last--;
	while(it != myset.end()) {
		if(it == last)
			res = min(res,max(0,d-(mx-val)));
		else
			res = min(res,max(0,d-((*it)-mn))+max(0,d-(mx-val)));
		val = (*it);
		it++;
	}
	return res;
}

void solve() {
	for( int i = 0 , mn , mx ; i < n ; i++ ) {
		myset.insert(ar[i]);
		if(i == 0) {
			mn = mx = ar[0];
			printf("0 ");
		}
		else if(i == 1) {
			mn = min(mn,ar[1]);
			mx = max(mx,ar[1]);
			printf("%d ",max(0,d-(mx-mn)));
		}
		else {
			mn = min(mn,ar[i]);
			mx = max(mx,ar[i]);
			printf("%d ",f(mn,mx));
		}
	}
	puts("");
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		myset.clear();
		input();
		solve();
	}
	return 0;
}
