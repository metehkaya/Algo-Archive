#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int n,ans;
set<pi> s;

int main() {
	scanf("%d",&n);
	for( int i = 0 , a,b ; i < n ; i++ ) {
		scanf("%d%d",&a,&b);
		s.insert(pi(a,+1));
		s.insert(pi(b,-1));
	}
	int cnt = 0;
	for( auto it = s.begin() ; it != s.end() ; it++ ) {
		cnt += it->second;
		ans = max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}