#include <bits/stdc++.h>
#define maxn 5003
#define mod 1000000007
using namespace std;
typedef long long LL;

int x,y;
int comb[maxn][maxn];

int main() {
	for( int i = 0 ; i < maxn ; i++ )
		comb[i][0] = 1;
	for( int i = 1 ; i < maxn ; i++ )
		for( int j = 1 ; j <= i ; j++ )
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
	scanf("%d%d",&x,&y);
	printf("%d\n",comb[x][y]);
	return 0;
}
