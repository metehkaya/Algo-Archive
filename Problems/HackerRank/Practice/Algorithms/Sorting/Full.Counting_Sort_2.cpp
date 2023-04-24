#include <bits/stdc++.h>
#define maxc 100
using namespace std;

int n;
int cnt[maxc];

int main() {
	scanf("%d",&n);
	for( int i = 0 , v ; i < n ; i++ ) {
		scanf("%d",&v);
		cnt[v]++;
	}
	for( int i = 0 ; i < maxc ; i++ )
		for( int j = 0 ; j < cnt[i] ; j++ )
			printf("%d ",i);
	puts("");
	return 0;
}
