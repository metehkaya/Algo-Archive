#include <bits/stdc++.h>
#define maxn 500001
#define mod 1000000007
using namespace std;
typedef long long LL;

int T,n;
int ans[maxn];
int cnt[maxn];
LL fact[maxn];
LL invFact[maxn];
LL combSum[maxn];
vector<int> nums[maxn];

void reset() {
	for( int i = 1 ; i <= n ; i++ )
		ans[i] = cnt[i] = 0 , nums[i].clear();
}

LL calcPow(LL x , int y) {
	if(y == 0)
		return 1;
	LL res = calcPow(x,y/2);
	res = (res * res) % mod;
	if(y & 1)
		res = (res * x) % mod;
	return res;
}

LL calcInv(LL x) {
	return calcPow(x,mod-2);
}

LL calcComb(int x , int y) {
	LL res = (fact[x] * invFact[y]) % mod;
	res = (res * invFact[x-y]) % mod;
	return res;
}

int main() {
	fact[0] = invFact[0] = 1;
	for( int i = 1 ; i < maxn ; i++ ) {
		fact[i] = (fact[i-1] * i) % mod;
		invFact[i] = calcInv(fact[i]);
	}
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 1 , val ; i <= n ; i++ ) {
			scanf("%d",&val);
			cnt[val]++;
		}
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= cnt[i] ; j++ )
				nums[j].push_back(i);
		LL subset = 1;
		for( int i = 1 ; i <= n ; i++ )
			combSum[i] = 1;
		for( int c = 1 ; c <= n ; c++ )
			for( int i = nums[c].size()-1 ; i >= 0 ; i-- ) {
				int num = nums[c][i];
				int numCnt = cnt[num];
				LL other = (subset * calcInv(combSum[num])) % mod;
				LL comb = calcComb(numCnt,c);
				LL add = (other * comb) % mod;
				ans[num] = (ans[num] + add) % mod;
				combSum[num] = (combSum[num] + comb) % mod;
				subset = (other * combSum[num]) % mod;
			}
		for( int i = 1 ; i <= n ; i++ )
			printf("%lld ",ans[i]);
		puts("");
	}
	return 0;
}
