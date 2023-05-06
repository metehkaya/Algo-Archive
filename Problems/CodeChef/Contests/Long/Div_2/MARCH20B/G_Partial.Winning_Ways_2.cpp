#include <bits/stdc++.h>
#define maxc 1003
#define maxn 100003
#define mod 998244353
#define pb push_back
using namespace std;
typedef map<int,int>::iterator mit;

int T,n,m;
int ar[maxn];
int comb[maxc][maxc];

void precalc() {
	for( int i = 0 ; i < maxc ; i++ )
		comb[i][0] = 1;
	for( int i = 1 ; i < maxc ; i++ )
		for( int j = 1 ; j <= i ; j++ )
			comb[i][j] = ( comb[i-1][j] + comb[i-1][j-1] ) % mod;
}

int main() {
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		scanf("%d",&m);
		for( int q = 1 ; q <= m ; q++ ) {
			int l,r,ans=0,cntXor=0;
			vector<int> vec;
			map<int,int> hashh;
			scanf("%d%d",&l,&r);
			for( int i = l ; i <= r ; i++ )
				hashh[ar[i]]++;
			for( mit miter = hashh.begin() ; miter != hashh.end() ; miter++ ) {
				int cnt = miter->second;
				vec.pb(cnt);
				cntXor ^= cnt;
			}
			for( int i = 0 ; i < (int) vec.size() ; i++ ) {
				int target = (cntXor ^ vec[i]);
				if(target < vec[i])
					ans = ( ans + comb[vec[i]][target] ) % mod;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
