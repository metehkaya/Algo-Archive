#include <bits/stdc++.h>
using namespace std;

int n,m;
multiset<int> s;

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		s.insert(x);
	}
	for( int i = 0 , x ; i < m ; i++ ) {
		scanf("%d",&x);
		auto it = s.upper_bound(x);
		if(it == s.begin())
			puts("-1");
		else {
			it--;
			printf("%d\n",*it);
			s.erase(it);
		}
	}
	return 0;
}