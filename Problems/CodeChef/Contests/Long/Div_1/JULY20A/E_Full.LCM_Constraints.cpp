#include <bits/stdc++.h>
#define fi first
#define se second
#define maxp 5
#define maxn 38
#define maxm 10000
#define mod 1000000007
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

int T,n,m,npr,ans,res,mxp;
int x[maxm];
int y[maxm];
int r[maxm];
LL needs[maxn];
bool force[maxn];
set<int> primes;
vector<int> p[maxm];
vector<int> e[maxm];
vector<int> newSeens;
map<int,int> primeIds;
vector<pii> factors[maxp];

void reset() {
	for( int i = 0 ; i < npr ; i++ )
		factors[i].clear();
	npr = 0;
	primes.clear();
	primeIds.clear();
	memset(needs,0,sizeof(needs));
	memset(force,false,sizeof(force));
	for( int i = 0 ; i < m ; i++ ) {
		p[i].clear();
		e[i].clear();
	}
}

void read() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < m ; i++ ) {
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
		x[i]--,y[i]--;
		if(x[i] > y[i])
			swap(x[i],y[i]);
		for( int j = 0 , pp , ee ; j < r[i] ; j++ ) {
			scanf("%d%d",&pp,&ee);
			p[i].push_back(pp);
			e[i].push_back(ee);
			primes.insert(pp);
		}
	}
}

bool checkInf() {
	bool var[n];
	memset(var,false,sizeof(var));
	for( int i = 0 ; i < m ; i++ )
		var[x[i]] = var[y[i]] = true;
	bool inf = false;
	for( int i = 0 ; i < n ; i++ )
		if(!var[i])
			return true;
	return false;
}

void calcPrimeIds() {
	set<int>::iterator it;
	for( it = primes.begin() ; it != primes.end() ; it++ )
		primeIds[(*it)] = npr++;
}

void calcPairs() {
	for( int i = 0 ; i < m ; i++ ) {
		int cntFactors[npr];
		memset(cntFactors,0,sizeof(cntFactors));
		for( int j = 0 ; j < r[i] ; j++ ) {
			int pp = p[i][j];
			int ee = e[i][j];
			pp = primeIds[pp];
			cntFactors[pp] += ee;
		}
		for( int j = 0 ; j < npr ; j++ )
			factors[j].pb(pii(cntFactors[j],pi(x[i],y[i])));
	}
}

void f(int i , LL bmask , int mult) {
	if(i == newSeens.size()) {
		res = (res + mult) % mod;
		return;
	}
	int num = newSeens[i];
	if(!force[num] && mxp)
		if((bmask & needs[num]) == needs[num])
			f( i+1 , bmask , (LL) mult * mxp % mod );
	f( i+1 , (bmask | (1LL<<num)) , mult );
}

int solve() {
	ans = 1;
	for( int i = 0 ; i < npr ; i++ )
		sort(factors[i].begin(),factors[i].end());
	for( int prID = 0 ; prID < npr ; prID++ ) {
		bool seen[n];
		memset(seen,false,sizeof(seen));
		bool newseen[n];
		memset(newseen,false,sizeof(newseen));
		for( int l = 0 , r = 0 ; l < m ; l = r ) {
			mxp = factors[prID][l].fi;
			while(r < m && factors[prID][r].fi == mxp)
				r++;
			for( int i = l ; i < r ; i++ ) {
				int a = factors[prID][i].se.fi;
				int b = factors[prID][i].se.se;
				if(seen[a] && seen[b])
					return 0;
				if(a == b)
					force[a] = newseen[a] = true;
				else if(!seen[a] && !seen[b]) {
					needs[b] |= (1LL<<a);
					newseen[a] = newseen[b] = true;
				}
				else if(!seen[a])
					force[a] = newseen[a] = true;
				else
					force[b] = newseen[b] = true;
			}
			newSeens.clear();
			for( int i = 0 ; i < n ; i++ )
				if(newseen[i])
					newSeens.pb(i);
			res = 0;
			f(0,0,1);
			ans = (LL) ans * res % mod;
			for( int i = 0 ; i < newSeens.size() ; i++ )
				seen[newSeens[i]] = true;
		}
	}
	return ans;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		read();
		if(checkInf()) {
			puts("-1");
			continue;
		}
		calcPrimeIds();
		calcPairs();
		printf("%d\n",solve());
	}
	return 0;
}
