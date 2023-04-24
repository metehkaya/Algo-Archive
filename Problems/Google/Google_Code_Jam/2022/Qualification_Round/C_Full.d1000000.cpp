#include <bits/stdc++.h>
using namespace std;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		multiset<int> s;
		for( int i = 1 , x ; i <= n ; i++ ) {
			scanf("%d",&x);
			s.insert(x);
		}
		int ans = 0;
		multiset<int>::iterator mit;
		while(ans < n) {
			mit = s.upper_bound(ans);
			if(mit == s.end())
				break;
			s.erase(mit);
			ans++;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
