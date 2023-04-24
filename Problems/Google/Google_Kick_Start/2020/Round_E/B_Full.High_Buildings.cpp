#include <bits/stdc++.h>
#define maxn 103
#define pb push_back
using namespace std;

int T,n,a,b,c;
int ans[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d%d",&n,&a,&b,&c);
		if(n == 1) {
			printf("Case #%d: 1\n",tc);
			continue;
		}
		else if(n == 2) {
			if(c == 1) {
				if(a == 1 && b == 1)
					printf("Case #%d: IMPOSSIBLE\n",tc);
				else if(a == 1 && b == 2)
					printf("Case #%d: 2 1\n",tc);
				else if(a == 2 && b == 1)
					printf("Case #%d: 1 2\n",tc);
				else
					printf("Case #%d: IMPOSSIBLE\n",tc);
			}
			else
				printf("Case #%d: 1 1\n",tc);
			continue;
		}
		int sum = c+(a-c)+(b-c);
		int rem = n-sum;
		if(rem < 0) {
			printf("Case #%d: IMPOSSIBLE\n",tc);
			continue;
		}
		else if(c < b) {
			int idx = 0;
			for( int i = 0 ; i < a-c ; i++ )
				ans[++idx] = 2;
			for( int i = 0 ; i < c ; i++ )
				ans[++idx] = 3;
			for( int i = 0 ; i < rem ; i++ )
				ans[++idx] = 1;
			for( int i = 0 ; i < b-c ; i++ )
				ans[++idx] = 2;
		}
		else if(c < a) {
			int idx = 0;
			for( int i = 0 ; i < a-c ; i++ )
				ans[++idx] = 2;
			for( int i = 0 ; i < rem ; i++ )
				ans[++idx] = 1;
			for( int i = 0 ; i < c ; i++ )
				ans[++idx] = 3;
			for( int i = 0 ; i < b-c ; i++ )
				ans[++idx] = 2;
		}
		else {
			if(c >= 2) {
				ans[1] = 2;
			    for( int i = 2 ; i <= rem+1 ; i++ )
			        ans[i] = 1;
			    for( int i = rem+2 ; i <= n ; i++ )
			        ans[i] = 2;
			}
			else {
			    printf("Case #%d: IMPOSSIBLE\n",tc);
			    continue;
			}
		}
		printf("Case #%d:",tc);
		for( int i = 1 ; i <= n ; i++ )
			printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
