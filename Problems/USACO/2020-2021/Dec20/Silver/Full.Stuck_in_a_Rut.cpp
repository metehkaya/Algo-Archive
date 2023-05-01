#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

struct cow {
	int x,y,id;
	char type;
	int last;
} ar[maxn];

int n;
int ans[maxn];
bool mark[maxn];
vector<int> adj[maxn];

bool comp(const cow& a , const cow& b) {
	return a.x + a.y > b.x + b.y;
}

void dfs(int u) {
	mark[u] = true;
	int deg = adj[u].size();
	for( int i = 0 ; i < deg ; i++ ) {
		int v = adj[u][i];
		if(!mark[v])
			dfs(v);
		ans[u] += ans[v]+1;
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		string s;
		cin >> s >> ar[i].x >> ar[i].y;
		ar[i].type = s[0];
		ar[i].id = i;
	}
	sort(ar,ar+n,comp);
	for( int i = 0 , j = 0 ; i < n ; i = j ) {
		while(j < n && ar[i].x + ar[i].y == ar[j].x + ar[j].y)
			j++;
		for( int k = i ; k < j ; k++ ) {
			int by = -1;
			ar[k].last = INT_MAX;
			for( int l = 0 ; l < i ; l++ ) {
				if(ar[k].type == 'E' && ar[l].type == 'E') {
					if(ar[k].y == ar[l].y && ar[l].x < ar[k].last)
						ar[k].last = ar[l].x , by = l;
				}
				else if(ar[k].type == 'E' && ar[l].type == 'N') {
					if(ar[l].y <= ar[k].y && ar[l].last > ar[k].y && ar[l].x < ar[k].last)
						ar[k].last = ar[l].x , by = l;
				}
				else if(ar[k].type == 'N' && ar[l].type == 'N') {
					if(ar[k].x == ar[l].x && ar[l].y < ar[k].last)
						ar[k].last = ar[l].y , by = l;
				}
				else {
					if(ar[l].x <= ar[k].x && ar[l].last > ar[k].x && ar[l].y < ar[k].last)
						ar[k].last = ar[l].y , by = l;
				}
			}
			if(by != -1)
				adj[ar[by].id].push_back(ar[k].id);
		}
	}
	for( int i = 0 ; i < n ; i++ )
		if(!mark[i])
			dfs(i);
	for( int i = 0 ; i < n ; i++ )
		printf("%d\n",ans[i]);
	return 0;
}
