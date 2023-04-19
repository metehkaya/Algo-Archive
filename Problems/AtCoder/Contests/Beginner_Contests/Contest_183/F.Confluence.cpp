#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200003
using namespace std;

int n,m;
int c[maxn];
int dad[maxn];
map<int, map<int,int> > mp;

int findDad(int u) {
	if(dad[u] == 0)
		return u;
	return dad[u] = findDad(dad[u]);
}

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&c[i]);
		mp[i][c[i]] = 1;
	}
	map<int,int>::iterator it;
	for( int i = 0 , t,x,y ; i < m ; i++ ) {
		scanf("%d%d%d",&t,&x,&y);
		if(t == 1) {
			x = findDad(x);
			y = findDad(y);
			if(x == y)
				continue;
			if(mp[x].size() < mp[y].size()) {
				for(it = mp[x].begin() ; it != mp[x].end() ; it++)
					mp[y][it->fi] += it->se;
				mp[x].clear();
				dad[x] = y;
			}
			else {
				for(it = mp[y].begin() ; it != mp[y].end() ; it++)
					mp[x][it->fi] += it->se;
				mp[y].clear();
				dad[y] = x;
			}
		}
		else {
			x = findDad(x);
			it = mp[x].find(y);
			if(it == mp[x].end())
				puts("0");
			else
				printf("%d\n",it->se);
		}
	}
	return 0;
}
