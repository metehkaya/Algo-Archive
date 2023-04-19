#include <bits/stdc++.h>
#define maxn 18
#define maxN (1<<maxn)
using namespace std;

int N,n,m;
int dp[maxN];
bool comp[maxN];
bool e[maxn][maxn];
vector<int> v;

void f(int curr , int bmask) {
	comp[bmask] = true;
	if(curr == n)
		return;
	f(curr+1,bmask);
	int sz = v.size();
	bool ok = true;
	for( int i = 0 ; i < sz ; i++ )
		if(!e[v[i]][curr]) {
			ok = false;
			break;
		}
	if(ok) {
		v.push_back(curr);
		f(curr+1,(bmask|(1<<curr)));
		v.pop_back();
	}
}

void g(int bmask , int add , int idx , int sz) {
	if(idx == sz) {
		if(add)
			dp[bmask] = min(dp[bmask],dp[bmask+add]+1);
		return;
	}
	g(bmask,add,idx+1,sz);
	int add2 = (add + (1<<v[idx]));
	if(comp[add2])
		g(bmask,add2,idx+1,sz);
}

int main() {
	scanf("%d%d",&n,&m);
	N = (1<<n);
	for( int i = 0 , u,w ; i < m ; i++ ) {
		scanf("%d%d",&u,&w);
		u--,w--;
		e[u][w] = true;
	}
	for( int i = 0 ; i < n ; i++ ) {
		v.push_back(i);
		f(i+1,(1<<i));
		v.pop_back();
	}
	dp[N-1] = 0;
	for( int bmask = N-2 ; bmask >= 0 ; bmask-- ) {
		v.clear();
		for( int i = 0 ; i < n ; i++ )
			if((bmask & (1<<i)) == 0)
				v.push_back(i);
		dp[bmask] = n+5;
		g(bmask,0,0,v.size());
	}
	printf("%d\n",dp[0]);
	return 0;
}
