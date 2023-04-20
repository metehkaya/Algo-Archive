#include <bits/stdc++.h>
using namespace std;

int n;
multiset<int> s;

int main() {
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		auto it = s.upper_bound(x);
		if(it != s.end())
			s.erase(it);
		s.insert(x);
	}
	printf("%d\n",s.size());
	return 0;
}