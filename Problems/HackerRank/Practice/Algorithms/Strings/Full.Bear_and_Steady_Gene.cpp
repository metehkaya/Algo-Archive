#include <bits/stdc++.h>
#define maxn 500003
using namespace std;

int n;
char s[maxn];
int hashh[256];
int sum[maxn][4];

bool checkSteadyAlready() {
	for( int i = 0 ; i < 4 ; i++ )
		if( sum[n][i] != n/4 )
			return false;
	return true;
}

bool checkSteadyPossible(int l, int r) {
	for( int i = 0 ; i < 4 ; i++ ) {
		int val = sum[n][i] - sum[r][i] + sum[l-1][i];
		if(val > n/4)
			return false;
	}
	return true;
}

int main() {
	hashh['C'] = 1;
	hashh['G'] = 2;
	hashh['T'] = 3;
	scanf("%d%s",&n,s+1);
	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = 0 ; j < 4 ; j++ )
			sum[i][j] = sum[i-1][j];
		sum[i][hashh[(int)s[i]]]++;
	}
	if(checkSteadyAlready())
		puts("0");
	else {
		int ans = n;
		for( int i = 1 ; i <= n ; i++ ) {
			int l=i , r=n;
			while(l <= r) {
				int mid = (l+r) >> 1;
				if(checkSteadyPossible(i,mid)) {
					ans = min(ans, mid-i+1);
					r = mid-1;
				}
				else
					l = mid+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
