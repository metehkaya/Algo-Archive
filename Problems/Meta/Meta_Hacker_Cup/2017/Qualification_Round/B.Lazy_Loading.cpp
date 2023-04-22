#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int T,n;
int ar[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		sort(ar,ar+n);
		int ans = 0 , i = n-1 , j = 0;
		while(i >= 0 && ar[i] >= 50)
			i-- , ans++;
		while(i > j) {
			int cnt = 50/ar[i] + !(!(50%ar[i])) - 1;
			j += cnt;
			if(j > i)
				break;
			i-- , ans++;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
