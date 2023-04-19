#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;

LL ans;
int n,c;
map<int,LL> mp;

int main() {
	scanf("%d%d",&n,&c);
	for( int i = 0 , x,y,z ; i < n ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		mp[x] += z;
		mp[y+1] -= z;
	}
	LL curr = 0;
	map<int,LL>::iterator it1,it2;
	it1 = mp.begin();
	it2 = it1;
	it2++;
	while(it2 != mp.end()) {
		curr += it1->se;
		LL add = min(curr,(LL)c);
		int len = it2->fi - it1->fi;
		ans += add*len;
		it1++,it2++;
	}
	printf("%lld\n",ans);
	return 0;
}
