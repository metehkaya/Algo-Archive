#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;

int n,k,neg;
map<LL,int> hashh;

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		hashh[(LL)x-(LL)i*(LL)k]++;
	}
	map<LL,int>::iterator mit = hashh.begin();
	while(mit != hashh.end()) {
		neg = max(neg,(*mit).se);
		mit++;
	}
	printf("%d\n",n-neg);
	return 0;
}
