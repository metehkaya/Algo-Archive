#include <bits/stdc++.h>
#define maxn 100001
using namespace std;

int n,m;
int sum[maxn][3];

int main() {
	freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);
	scanf("%d%d",&n,&m);
	for( int i = 1 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		for( int j = 0 ; j < 3 ; j++ )
			sum[i][j] = sum[i-1][j] + ((x-1) == j);
	}
	for( int i = 0 , l,r ; i < m ; i++ ) {
		scanf("%d%d",&l,&r);
		for( int j = 0 ; j < 3 ; j++ ) {
			printf("%d",sum[r][j]-sum[l-1][j]);
			if(j < 2)
				printf(" ");
		}
		puts("");
	}
	return 0;
}
