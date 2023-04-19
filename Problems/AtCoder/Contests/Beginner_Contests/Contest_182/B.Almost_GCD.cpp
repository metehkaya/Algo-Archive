#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int n;
int ans,best;
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int num = 2 ; num <= 1000 ; num++ ) {
		int cnt = 0;
		for( int i = 0 ; i < n ; i++ )
			if(ar[i]%num == 0)
				cnt++;
		if(cnt > best) {
			ans = num;
			best = cnt;
		}
	}
	printf("%d\n",ans);
	return 0;
}
