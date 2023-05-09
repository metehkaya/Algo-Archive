#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

int n;
int ans[maxn];
int res[maxn][2];

int main() {
	scanf("%d",&n);
	int idx = 1;
	for( int i = 2 ; i <= n ; i++ ) {
		int a,b;
		printf("? %d %d\n",i,idx);
		fflush(stdout);
		scanf("%d",&a);
		printf("? %d %d\n",idx,i);
		fflush(stdout);
		scanf("%d",&b);
		if(a < b) {
			ans[idx] = b;
			idx = i;
		}
		else
			ans[i] = a;
	}
	ans[idx] = n;
	printf("!");
	for( int i = 1 ; i <= n ; i++ )
		printf(" %d",ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}
