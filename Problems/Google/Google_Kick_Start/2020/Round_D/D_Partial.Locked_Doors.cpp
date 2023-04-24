#include <bits/stdc++.h>
#define maxn 100001
using namespace std;

int T,n,m;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		printf("Case #%d:",tc);
		for( int q = 0 , s,k ; q < m ; q++ ) {
			scanf("%d%d",&s,&k);
			if(s == 1)
				printf(" %d",k);
			else if(s == n)
				printf(" %d",n-k+1);
			else if(k == 1)
				printf(" %d",s);
			else {
				int l = s-1 , r = s , res = s;
				for( int i = 2 ; i <= k ; i++ ) {
					if(r != n && (l == 0 || ar[r] < ar[l]))
						res = ++r;
					else
						res = l--;
				}
				printf(" %d",res);
			}
		}
		puts("");
	}
	return 0;
}
