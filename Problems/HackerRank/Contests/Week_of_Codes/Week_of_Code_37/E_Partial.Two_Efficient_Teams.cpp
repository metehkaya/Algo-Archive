#include <bits/stdc++.h>
#define fi first
#define se second
#define maxm 500
#define maxs 50000000LL
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n,m,dfs_cnt;
LL ans,allor,sumvals;
LL ar[maxm];
int val[maxm];
int mark[maxm];
bool forb[maxm];
pi v2[maxm];
vector<LL>bmasks;

bool comp(pi a , pi b) {
	return a.fi < b.fi;
}

void dfs(int node) {
	mark[node] = dfs_cnt;
	for( int i = 0 ; i < m ; i++ )
		if(mark[i] != dfs_cnt && !forb[i])
			if((ar[node]&ar[i]) > 0LL)
				dfs(i);
}

bool dfsGeneral() {
	dfs_cnt++;
	int cnt = 0;
	for( int i = 0 ; i < m ; i++ )
		if(mark[i] != dfs_cnt && !forb[i]) {
			cnt++;
			if(cnt > 1)
				return true;
			dfs(i);
		}
	return false;
}

void tryMultiAPs() {
	for( int i = 0 ; i < m ; i++ )
		v2[i] = pi(val[i],i);
	sort(v2,v2+m,comp);
	int last = -1;
	for( int i = 0 ; i < m ; i++ ) {
		forb[v2[i].se] = true;
		if(i == m - 2 || dfsGeneral()) {
			last = i;
			break;
		}
	}
	for( int i = last-1 ; i >= 0 ; i-- ) {
		forb[v2[i].se] = false;
		if(!dfsGeneral())
			forb[v2[i].se] = true;
	}
	LL sum = sumvals;
	for( int i = 0 ; i < m ; i++ )
		if(forb[i])
			sum -= val[i];
	ans = max(ans,sum);
}

bool isArticulationPoint(int ap) {
	forb[ap] = true;
	bool res = dfsGeneral();
	forb[ap] = false;
	return res;
}

void trySingleAP() {
	for( int i = 0 ; i < m ; i++ )
		if(m == 2 || isArticulationPoint(i))
			ans = max(ans,sumvals-val[i]);
}

void amele() {
	for( int k = 0 ; k < bmasks.size() ; k++ ) {
		LL sum = 0;
		LL bmask = bmasks[k];
		LL bmask2 = (1LL<<n)-bmask-1;
		for( int i = 0 ; i < m ; i++ )
			if((bmask&ar[i]) == ar[i] || (bmask2&ar[i]) == ar[i])
				sum += val[i];
		ans = max(ans,sum);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , cnt , x ; i < m ; i++ ) {
		scanf("%d%d",&cnt,&val[i]);
		sumvals += val[i];
		for( int j = 0 ; j < cnt ; j++ ) {
			scanf("%d",&x);
			x--;
			ar[i] |= (1LL<<x);
			allor |= (1LL<<x);
		}
	}
	if(allor != (1LL<<n)-1 || dfsGeneral()) {
		printf("%lld\n",sumvals);
		return 0;
	}
	if(m == 1) {
		puts("0");
		return 0;
	}
	if((1LL<<(n-1)) * m <= maxs) {
		for( LL bmask = 1 ; bmask < (1LL<<(n-1)) ; bmask++ )
			bmasks.pb( bmask );
		amele();
	}
	else {
		for( int i = 0 ; i < n ; i++ )
			bmasks.pb((1LL<<i));
		amele();
		trySingleAP();
		tryMultiAPs();
	}
	printf("%lld\n",ans);
	return 0;
}
