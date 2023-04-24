#include <bits/stdc++.h>
#define maxn 10005
#define pb push_back
using namespace std;
typedef long long LL;

struct data {
	int to,len;
};

bool operator<(const data &a , const data &b) {
	return a.len > b.len;
}

data getData(int _to , int _len) {
	data tmp;
	tmp.to = _to;
	tmp.len = _len;
	return tmp;
}

int n,m,k;
int mark[maxn];
vector<data> adj[maxn];
priority_queue<data> heap;

int main() {
	scanf("%d%d%d",&n,&k,&m);
	for( int i = 0 , x , y , z ; i < m ; i++ ) {
		scanf("%d%d%d",&x,&y,&z);
		adj[x].pb(getData(y,z));
		adj[y].pb(getData(x,z));
	}
	heap.push(getData(1,0));
	while(!heap.empty()) {
		data tmp = heap.top();
		heap.pop();
		int node = tmp.to;
		int length = tmp.len;
		if(node == n) {
			printf("%d\n",length);
			break;
		}
		if(mark[node] == 2)
			continue;
		if((length/k) % 2) {
			if(mark[node] == 1)
				continue;
			mark[node] = 1;
			int x = length / (2*k);
			heap.push(getData(node,(x+1)*(2*k)));
			continue;
		}
		mark[node] = 2;
		for( int i = 0 ; i < adj[node].size() ; i++ ) {
			int to = adj[node][i].to;
			int len = adj[node][i].len;
			if(!mark[to])
				heap.push(getData(to,length+len));
		}
	}
	return 0;
}
