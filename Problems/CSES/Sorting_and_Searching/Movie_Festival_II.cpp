#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200000
using namespace std;
typedef pair<int,int> pi;

int n,k,ans;
pi ar[maxn];
multiset<int> s;

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 , x ; i < n ; i++ )
		scanf("%d%d",&ar[i].se,&ar[i].fi);
	sort(ar,ar+n);
	for( int i = 0 ; i < k ; i++ )
		s.insert(0);
	for( int i = 0 ; i < n ; i++ ) {
		int st = ar[i].se;
		int en = ar[i].fi;
		auto it = s.upper_bound(st);
		if(it != s.begin()) {
			ans++;
			it--;
			s.erase(it);
			s.insert(en);
		}
	}
	printf("%d\n",ans);
	return 0;
}