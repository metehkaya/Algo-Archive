#include <bits/stdc++.h>
#define maxn 1001
using namespace std;

int n,m,k,mx;
int ar[71][71];
int dp2[71][71];
int dp3[71][71];
int dp1[71][71][71];

void calcDP1() {
	memset(dp1,-1,sizeof(dp1));
	for( int i = 1 ; i <= n ; i++ ) {
		dp1[i][0][0] = 0;
		for( int j = 1 ; j <= m ; j++ ) {
			int val = ar[i][j];
			int add = val%k;
			for( int r = mx-1 ; r >= 0 ; r-- )
				for( int c = 0 ; c < k ; c++ )
					if(dp1[i][r][c] != -1) {
						int r2 = r+1;
						int c2 = (c+add)%k;
						dp1[i][r2][c2] = max( dp1[i][r2][c2] , dp1[i][r][c] + val );
					}
		}
	}
}

void calcDP2() {
	memset(dp2,-1,sizeof(dp2));
	for( int i = 1 ; i <= n ; i++ )
		for( int r = 0 ; r <= mx ; r++ )
			for( int c = 0 ; c < k ; c++ )
				dp2[i][c] = max(dp2[i][c],dp1[i][r][c]);
}

void calcDP3() {
	memset(dp3,-1,sizeof(dp3));
	dp3[0][0] = 0;
	for( int i = 1 ; i <= n ; i++ )
		for( int j1 = 0 ; j1 < k ; j1++ )
			if(dp2[i][j1] != -1)
				for( int j2 = 0 ; j2 < k ; j2++ )
					if(dp3[i-1][j2] != -1) {
						int j3 = (j1+j2)%k;
						dp3[i][j3] = max(dp3[i][j3],dp3[i-1][j2]+dp2[i][j1]);
					}
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			scanf("%d",&ar[i][j]);
	mx = m/2;
	calcDP1();
	calcDP2();
	calcDP3();
	printf("%d\n",dp3[n][0]);
	return 0;
}
