#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

int n,x,ans;
int v[maxn];
int p[maxn];

int main() {
	ans = -1;
	scanf("%d%d",&n,&x);
	x *= 100;
	for( int i = 1 , v,p ; i <= n ; i++ ) {
		scanf("%d%d",&v,&p);
		x -= v*p;
		if(x < 0) {
			ans = i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
