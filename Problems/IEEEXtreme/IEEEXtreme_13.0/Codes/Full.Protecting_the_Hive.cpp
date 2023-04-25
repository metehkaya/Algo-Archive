#include <bits/stdc++.h>
#define maxn 101
#define maxs 10001
#define pb push_back
using namespace std;

int n,m,q;
int sz[maxs];
int dad[maxs];
int rankk[maxs];
int var[maxn][maxn];

int conv2id(int r, int c) {
	int p = (r-1)/2;
	int id = p*(2*m-1)+c;
	if(r%2==0)
		id += m;
	return id;
}

void checkBottomRight(int r, int c, vector<int>& v) {
	if(r==n)
		return;
	if(r%2 == 1 && c <= m-1 && var[r+1][c])
		v.pb(conv2id(r+1,c));
	else if(r%2 == 0 && var[r+1][c+1])
		v.pb(conv2id(r+1,c+1));
}

void checkBottomLeft(int r, int c, vector<int>& v) {
	if(r==n)
		return;
	if(r%2 == 1 && c-1 >= 1 && var[r+1][c-1])
		v.pb(conv2id(r+1,c-1));
	else if(r%2 == 0 && var[r+1][c])
		v.pb(conv2id(r+1,c));
}

void checkTopRight(int r, int c, vector<int>& v) {
	if(r==1)
		return;
	if(r%2 == 1 && c <= m-1 && var[r-1][c])
		v.pb(conv2id(r-1,c));
	else if(r%2 == 0 && var[r-1][c+1])
		v.pb(conv2id(r-1,c+1));
}

void checkTopLeft(int r, int c, vector<int>& v) {
	if(r==1)
		return;
	if(r%2 == 1 && c-1 >= 1 && var[r-1][c-1])
		v.pb(conv2id(r-1,c-1));
	else if(r%2 == 0 && var[r-1][c])
		v.pb(conv2id(r-1,c));
}

void checkRight(int r, int c, vector<int>& v) {
	if(r%2 == 1 && c+1 <= m && var[r][c+1])
		v.pb(conv2id(r,c+1));
	else if(r%2 == 0 && c+1 <= m-1 && var[r][c+1])
		v.pb(conv2id(r,c+1));
}

void checkLeft(int r, int c, vector<int>& v) {
	if(c-1 >= 1 && var[r][c-1])
		v.pb(conv2id(r,c-1));
}

void checkAdj(int r, int c, vector<int>& v) {
	checkLeft(r,c,v);
	checkRight(r,c,v);
	checkTopLeft(r,c,v);
	checkTopRight(r,c,v);
	checkBottomLeft(r,c,v);
	checkBottomRight(r,c,v);
}

int find(int u) {
	if(!dad[u])
		return u;
	return dad[u] = find(dad[u]);
}

void mergeAdj(int r, int c, vector<int>& v) {
	set<int>adj;
	for(int i = 0 ; i < (int) v.size() ; i++)
		adj.insert(find(v[i]));
	int myID = conv2id(r,c);
	int bestID = myID, sum = 6-2*v.size();
	set<int>::iterator it = adj.begin();
	while(it != adj.end()) {
		int to = (*it);
		sum += sz[to];
		if(rankk[to] > rankk[bestID])
			bestID = to;
		it++;
	}
	sz[bestID] = sum;
	adj.insert(myID);
	it = adj.begin();
	while(it != adj.end()) {
		int to = (*it);
		if(to != bestID) {
			dad[to] = bestID;
			if(rankk[to] == rankk[bestID])
				rankk[bestID]++;
		}
		it++;
	}
}

void add(int r, int c) {
	if(!var[r][c])
		return;
	vector<int>v;
	checkAdj(r,c,v);
	mergeAdj(r,c,v);
}

void input() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = 1 ; j < m ; j++ ) {
			scanf("%d",&var[i][j]);
			add(i,j);
		}
		if(i%2==1) {
			scanf("%d",&var[i][m]);
			add(i,m);
		}
	}
}

void query() {
	string inp;
	scanf("%d",&q);
	for(int i = 0 , x,y ; i < q ; i++) {
		cin >> inp;
		scanf("%d%d",&x,&y);
		if(inp[0] == 'a' && !var[x][y]) {
			var[x][y] = true;
			add(x,y);
		}
		else if(inp[0] == 'k')
			printf("%d\n",sz[find(conv2id(x,y))]);
	}
}

int main() {
	input();
	query();
	return 0;
}
