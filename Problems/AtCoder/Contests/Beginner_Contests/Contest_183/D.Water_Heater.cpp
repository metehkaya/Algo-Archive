#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;

int n,w;
map<int,LL> mp;

int main() {
	scanf("%d%d",&n,&w);
	for( int i = 0 , x,y,k ; i < n ; i++ ) {
		scanf("%d%d%d",&x,&y,&k);
		mp[x] += k;
		mp[y] -= k;
	}
	bool ans = true;
	map<int,LL>::iterator it;
	LL curr = 0;
	for( it = mp.begin() ; it != mp.end() ; it++ ) {
		curr += it->se;
		if(curr > w)
			ans = false;
	}
	if(ans)
		puts("Yes");
	else
		puts("No");
	return 0;
}
