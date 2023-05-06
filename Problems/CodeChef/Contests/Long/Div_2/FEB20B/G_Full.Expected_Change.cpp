#include <bits/stdc++.h>
#define maxn 10000005
#define mod 1000000007LL
using namespace std;
typedef long long LL;

int T,n;
LL stVal[2];
int stSize[2];
int sum[maxn];
char str[maxn];
int st[2][maxn];
int last[2*maxn];

LL calcPow(LL x, LL y) {
	if(y == 0)
		return 1;
	LL res = calcPow(x, y/2);
	res = (res * res) % mod;
	if(y % 2)
		res = (res * x) % mod;
	return res;
}

void reset() {
	memset(stVal, 0, sizeof(stVal));
	memset(stSize, 0, sizeof(stSize));
	memset(last, -1, sizeof(last));
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%s",&n,str+1);
		sum[0] = n+3;
		for( int i = 1 ; i <= n ; i++ ) {
			if(str[i] == '(')
				sum[i] = sum[i-1] + 1;
			else if(str[i] == ')')
				sum[i] = sum[i-1] - 1;
			else
				sum[i] = sum[i-1];
		}
		LL p = 0;
		for( int i = n ; i >= 1 ; i-- ) {
			int k = sum[i-1] % 2;
			if(str[i] == '(') {
				if( stSize[k] && last[sum[i-1]-2*stSize[k]+1] == -1 )
					stVal[k] -= st[k][--stSize[k]];
			}
			else if(str[i] == ')') {
				last[sum[i]] = n-i+1;
				if( last[sum[i-1]-2*stSize[k]-1] != -1 )
					stVal[k] += ( st[k][stSize[k]++] = n-i+1 );
				else {
					stVal[k] += n-i+1 - st[k][stSize[k]-1];
					st[k][stSize[k]-1] = n-i+1;
				}
			}
			p = (p + stVal[k]) % mod;
		}
		LL q = ( (LL) n * (n+1) / 2LL ) % mod;
		LL ans = ( p * calcPow(q,mod-2) ) % mod;
		printf("%lld\n",ans);
	}
	return 0;
}
