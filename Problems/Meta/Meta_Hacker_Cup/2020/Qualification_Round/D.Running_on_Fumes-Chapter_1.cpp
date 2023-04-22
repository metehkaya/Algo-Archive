#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;
typedef long long LL;

struct data {
	int id;
	LL cost;
};

bool operator<(const data &a , const data &b) {
	return a.cost > b.cost;
}

data newData(int id , LL cost) {
	data d;
	d.id = id;
	d.cost = cost;
	return d;
}

int T,n,k;
int ar[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&ar[i]);
		priority_queue<data> pq;
		pq.push(newData(0,0));
		for( int i = 1 ; i < n-1 ; i++ )
			if(ar[i]) {
				while(!pq.empty() && i - pq.top().id > k)
					pq.pop();
				if(!pq.empty()) {
					data d = pq.top();
					d.id = i;
					d.cost = d.cost + ar[i];
					pq.push(d);
				}
			}
		while(!pq.empty() && n-1 - pq.top().id > k)
			pq.pop();
		LL ans = pq.empty() ? -1 : pq.top().cost;
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
