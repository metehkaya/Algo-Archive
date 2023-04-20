#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200000
using namespace std;
typedef pair<int,int> pi;

int n,ans;
pi ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ )
		scanf("%d%d",&ar[i].se,&ar[i].fi);
	sort(ar,ar+n);
	for( int i = 0 , t = 0 ; i < n ; i++ )
		if(t <= ar[i].se) {
			ans++;
			t = ar[i].fi;
		}
	printf("%d\n",ans);
	return 0;
}