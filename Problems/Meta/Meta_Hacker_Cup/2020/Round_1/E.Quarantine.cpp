#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define maxn 1000003
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n,k,m;
LL ans[2];
LL e[maxn];
LL ae,be,ce;
LL initPairs;
pi Qu[maxn];
bool ok[maxn];
char str[maxn];
int colID[maxn];
int cntCol[maxn];
int stSize[maxn];
int sumCol[maxn];
map<int,int> treeCnt;
vector<int> adj[maxn];
map<int,int> cnts[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	m = 0;
	treeCnt.clear();
	initPairs = 0;
	ans[0] = ans[1] = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		colID[i] = 0;
		cntCol[i] = 0;
		stSize[i] = 0;
		sumCol[i] = 0;
		adj[i].clear();
		cnts[i].clear();
	}
}

LL comb(int X) {
	LL x = X;
	return x*(x-1)/2;
}

LL getCombInc(int x , int y , int z) {
	return comb(z) - comb(x) - comb(y);
}

void input() {
	scanf("%d%d%s",&n,&k,str+1);
	for( int i = 2 ; i <= k+1 ; i++ )
		scanf("%lld",&e[i]);
	scanf("%lld%lld%lld",&ae,&be,&ce);
	for( int i = k+2 ; i <= n ; i++ ) {
		e[i] = ae*e[i-2] + be*e[i-1] + ce;
		e[i] = e[i] % (i-1) + 1;
	}
	for( int i = 1 ; i <= n ; i++ )
		ok[i] = (str[i] == '*');
	for( int i = 2 ; i <= n ; i++ ) {
		adj[i].pb(e[i]);
		adj[e[i]].pb(i);
	}
}

void bfsCol(int u) {
	queue<int> Q;
	Q.push(u);
	colID[u] = m;
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		cntCol[m]++;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(ok[v] && !colID[v]) {
				colID[v] = m;
				Q.push(v);
			}
		}
	}
}

int getRoot() {
	return (LL)rand()*rand()%n+1;
}

void calc(int u , int dad) {
	LL gain = 0;
	int x=0,y=0,z=0;
	if(ok[u] && ok[dad]) {
		x = sumCol[u];
		z = cntCol[colID[u]];
		y = z-x;
		gain = -getCombInc(x,y,z);
		treeCnt[x]++;
		treeCnt[y]++;
		if(--treeCnt[z] == 0)
			treeCnt.erase(z);
	}
	map<int,int>::iterator it;
	map<int,int>::reverse_iterator rit;
	rit = cnts[u].rbegin();
	int a1 = rit->fi , b1 = rit->se , a2=-1 , b2=-1;
	for( rit = treeCnt.rbegin() ; rit != treeCnt.rend() ; rit++ ) {
		int a = rit->fi , b = rit->se;
		it = cnts[u].find(a);
		if(it == cnts[u].end()) {
			a2 = a;
			b2 = b;
			break;
		}
		else if(b > it->se) {
			a2 = a;
			b2 = b - (it->se);
			break;
		}
	}
	LL temp[2];
	if(min(a1,a2) == 0) {
		temp[0] = gain;
		temp[1] = (LL) stSize[u] * (n-stSize[u]);
	}
	else {
		gain += getCombInc(a1,a2,a1+a2);
		temp[0] = gain;
		temp[1] = (LL) a1*b1*a2*b2;
	}
	if(temp[0] > ans[0]) {
		ans[0] = temp[0];
		ans[1] = temp[1];
	}
	else if(temp[0] == ans[0])
		ans[1] += temp[1];
	if(z) {
		if(--treeCnt[x] == 0)
			treeCnt.erase(x);
		if(--treeCnt[y] == 0)
			treeCnt.erase(y);
		treeCnt[z]++;
	}
}

void bfs(int root) {
	Qu[1] = pi(root,0);
	for( int l = 1 , r = 1 ; l <= n ; l++ ) {
		int u = Qu[l].fi;
		int dad = Qu[l].se;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(v != dad)
				Qu[++r] = pi(v,u);
		}
	}
	for( int order = n ; order >= 1  ; order-- ) {
		int u = Qu[order].fi;
		int dad = Qu[order].se;
		map<int,int>::iterator it;
		stSize[u] = 1;
		int deg = adj[u].size();
		for( int i = 0 ; i < deg ; i++ ) {
			int v = adj[u][i];
			if(v != dad) {
				stSize[u] += stSize[v];
				if(cnts[u].size() < cnts[v].size())
					cnts[u].swap(cnts[v]);
				for( it = cnts[v].begin() ; it != cnts[v].end() ; it++ ) {
					int x = (*it).fi;
					int y = (*it).se;
					cnts[u][x] += y;
				}
				cnts[v].clear();
			}
		}
		if(ok[u]) {
			int total = 1;
			for( int i = 0 ; i < deg ; i++ ) {
				int v = adj[u][i];
				if(v != dad && sumCol[v]) {
					total += sumCol[v];
					if(--cnts[u][sumCol[v]] == 0)
						cnts[u].erase(sumCol[v]);
				}
			}
			sumCol[u] = total;
			cnts[u][total]++;
		}
		else {
			sumCol[u] = 0;
			cnts[u][0]++;
		}
		if(dad)
			calc(u,dad);
	}
}

void solve() {
	for( int i = 1 ; i <= n ; i++ )
		if(ok[i] && !colID[i]) {
			m++;
			bfsCol(i);
			treeCnt[cntCol[m]]++;
			initPairs += comb(cntCol[m]);
		}
		else if(!ok[i])
			treeCnt[0]++;
	int root = getRoot();
	bfs(root);
}

int main() {
	srand(time(NULL));
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		printf("Case #%d: %lld %lld\n",tc,initPairs+ans[0],ans[1]);
	}
	return 0;
}
