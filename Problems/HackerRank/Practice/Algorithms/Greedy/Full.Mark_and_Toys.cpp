#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n,m,sum,ans;
int ar[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	sort(ar,ar+n);
	for( int i = 0 ; i < n ; i++ ) {
		sum += ar[i];
		if(sum <= m)
			ans++;
		else
			break;
	}
	printf("%d\n",ans);
	return 0;
}
