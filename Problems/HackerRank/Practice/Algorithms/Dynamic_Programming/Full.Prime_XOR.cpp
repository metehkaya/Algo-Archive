#include <bits/stdc++.h>
#define maxn 1001
#define maxv 8192
#define mod 1000000007
using namespace std;
typedef long long LL;

const int MIN = 3500;

int T,n;
int cnt[maxn];
int dp[maxn][maxv];
bool notPrime[maxv];

void findPrimes() {
	notPrime[0] = notPrime[1] = true;
	for( int i = 2 ; i < maxv ; i++ )
		if(!notPrime[i])
			for( int j = i*i ; j < maxv ; j += i )
				notPrime[j] = true;
}

int f(int id, int val) {
	if(id == maxn)
		return !notPrime[val];
	if(dp[id][val] != -1)
		return dp[id][val];
	int way0 = cnt[id] / 2 + 1;
	int way1 = (cnt[id] + 1) / 2;
	dp[id][val] = 0;
	dp[id][val] = ( dp[id][val] + ( (LL) way0 * f(id+1,val) ) % mod ) % mod;
	dp[id][val] = ( dp[id][val] + ( (LL) way1 * f(id+1,val^(MIN+id)) ) % mod ) % mod;
	return dp[id][val];
}

int main() {
	findPrimes();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		memset(dp, -1, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		scanf("%d",&n);
		for( int i = 0 , x ; i < n ; i++ ) {
			scanf("%d",&x);
			cnt[x-MIN]++;
		}
		printf("%d\n",f(0,0));
	}
	return 0;
}
