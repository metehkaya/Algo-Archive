#include <bits/stdc++.h>
#define maxn 200001
#define pb push_back
using namespace std;
typedef long long LL;

int T,n,k;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		if(n == 2 || k <= 2) {
			printf("Case #%d: 0\n",tc);
			puts("1");
			printf("1 %d 1\n",n);
		}
		else {
			int times = min(k-1,n-1);
			int high = k-1;
			int low = high - times + 1;
			int algo = (low+high) * times / 2;
			printf("Case #%d: %d\n",tc,algo-k);
			printf("%d\n",times+1);
			for( int i = 1 ; i < times ; i++ )
				printf("%d %d %d\n",i,i+1,k-i);
			printf("%d %d %d\n",times,n,k-times);
			printf("1 %d %d\n",n,k);
		}
	}
	return 0;
}
