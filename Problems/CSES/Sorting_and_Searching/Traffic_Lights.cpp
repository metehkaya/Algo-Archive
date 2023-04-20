#include <bits/stdc++.h>
#define maxn 200001
using namespace std;

int n,x;
int ar[maxn];
int ans[maxn];
set<int> s;

int main() {
	scanf("%d%d",&x,&n);
	s.insert(0);
	s.insert(x);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		s.insert(ar[i]);
	}
	auto it1 = s.begin() , it2 = s.begin();
	for( it2++ ; it2 != s.end() ; it1++ , it2++ )
		ans[n] = max( ans[n] , (*it2) - (*it1) );
	for( int i = n-1 ; i >= 1 ; i-- ) {
		int val = ar[i+1];
		s.erase(val);
		it1 = it2 = s.upper_bound(val);
		it1--;
		ans[i] = max( ans[i+1] , (*it2) - (*it1) );
	}
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",ans[i]);
	return 0;
}