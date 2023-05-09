#include <bits/stdc++.h>
using namespace std;

int T,n;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		int cnt = 0;
		scanf("%d",&n);
		for( int i = 1 , x ; i <= n ; i++ ) {
			scanf("%d",&x);
			cnt += x;
		}
		int num,times;
		if(cnt > n/2) {
			num = 1;
			times = cnt;
			if(times&1)
				times--;
		}
		else {
			num = 0;
			times = n-cnt;
		}
		printf("%d\n",times);
		for( int i = 0 ; i < times ; i++ )
			printf("%d ",num);
		puts("");
	}
	return 0;
}
