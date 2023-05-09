#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 500003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

const int MOD[2] = {1000000007,1000000009};

LL ans;
int n,k;
int ar[maxn];
int cnt[maxn];
int pw[maxn][2];
pi val[maxn];
map<int,int> mp;
map<pi,int> cntHash;
vector<int> idx[maxn];
map<int,int>::iterator it;

pi getVal(int p , int x , int y , pi val) {
	for( int i = 0 ; i < x ; i++ )
		val.fi = (val.fi - pw[p][0] + MOD[0]) % MOD[0];
	for( int i = 0 ; i < y ; i++ )
		val.fi = (val.fi + pw[p][0]) % MOD[0];
	for( int i = 0 ; i < x ; i++ )
		val.se = (val.se - pw[p][1] + MOD[1]) % MOD[1];
	for( int i = 0 ; i < y ; i++ )
		val.se = (val.se + pw[p][1]) % MOD[1];
	return val;
}

int main() {
	scanf("%d",&n);
	for( int i = 1 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		it = mp.find(x);
		if(it == mp.end())
			ar[i] = mp[x] = k++;
		else
			ar[i] = it->second;
	}
	pw[0][0] = pw[0][1] = 1;
	for( int i = 1 ; i < k ; i++ ) {
		pw[i][0] = 3LL * pw[i-1][0] % MOD[0];
		pw[i][1] = 3LL * pw[i-1][1] % MOD[1];
	}
	val[0].fi = val[0].se = 0;
	cntHash[pi(0,0)] = 1;
	for( int i = 1 , j = 0 ; i <= n ; i++ ) {
		int x = ar[i];
		int cntOld = cnt[x];
		cnt[x] = (cnt[x] + 1) % 3;
		int cntNew = cnt[x];
		idx[x].pb(i);
		int sz = idx[x].size();
		if(sz > 3) {
			while(j < idx[x][sz-4]) {
				cntHash[val[j]]--;
				j++;
			}
		}
		val[i] = getVal(x,cntOld,cntNew,val[i-1]);
		ans += cntHash[val[i]];
		cntHash[val[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}
