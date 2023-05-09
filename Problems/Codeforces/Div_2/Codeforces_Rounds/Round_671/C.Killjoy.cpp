#include <bits/stdc++.h>
#define maxn 1003
using namespace std;

int T,n,x,sum;
int cnt[3];
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		sum = 0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&n,&x);
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			sum += ar[i];
			if(ar[i] < x)
				cnt[0]++;
			else if(ar[i] == x)
				cnt[1]++;
			else
				cnt[2]++;
		}
		if(cnt[1] == n)
			puts("0");
		else if(sum == n*x || cnt[1] > 0)
			puts("1");
		else
			puts("2");
	}
	return 0;
}
