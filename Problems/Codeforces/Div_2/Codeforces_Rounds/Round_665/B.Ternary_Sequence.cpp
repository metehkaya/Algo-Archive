#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

int T;
int n[2][3];
int ar[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};

LL f(int o1 , int o2) {
	LL sum = 0;
	int cnt[2][3];
	for( int i = 0 ; i < 2 ; i++ )
		for( int j = 0 ; j < 3 ; j++ )
			cnt[i][j] = n[i][j];
	int i = 0 , j = 0;
	while(i < 3 && j < 3) {
		int i2 = ar[o1][i];
		int j2 = ar[o2][j];
		if(cnt[0][i2] == 0) {
			i++;
			continue;
		}
		if(cnt[1][j2] == 0) {
			j++;
			continue;
		}
		LL mn = min(cnt[0][i2],cnt[1][j2]);
		cnt[0][i2] -= mn;
		cnt[1][j2] -= mn;
		if(i2 > j2)
			sum += mn*i2*j2;
		else if(i2 < j2)
			sum -= mn*i2*j2;
	}
	return sum;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		for( int i = 0 ; i < 2 ; i++ )
			for( int j = 0 ; j < 3 ; j++ )
				scanf("%d",&n[i][j]);
		LL ans = LLONG_MIN;
		for( int i = 0 ; i < 6 ; i++ )
			for( int j = 0 ; j < 6 ; j++ )
				ans = max(ans,f(i,j));
		printf("%I64d\n",ans);
	}
	return 0;
}
