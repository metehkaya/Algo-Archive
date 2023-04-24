#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

int n,m;
int cnt[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		cnt[x]++;
	}
	for( int i = 0 ; i < m ; i++ )
		printf("%d ",cnt[i]);
	return 0;
}
