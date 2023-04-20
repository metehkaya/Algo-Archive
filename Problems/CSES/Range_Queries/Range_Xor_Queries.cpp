#include <bits/stdc++.h>
#define maxn 200001
using namespace std;

int n,m;
int ar[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		ar[i] ^= ar[i-1];
	}
	for( int i = 0 , x,y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		printf("%d\n",ar[y]^ar[x-1]);
	}
	return 0;
}