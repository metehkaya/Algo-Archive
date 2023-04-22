#include <bits/stdc++.h>
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long LL;

struct data {
	LL t;
	int id;
};

bool operator<(const data &a , const data &b) {
	return a.t > b.t;
}

data newData(LL t , int id) {
	data temp;
	temp.t = t;
	temp.id = id;
	return temp;
}

int T,l,n,m,d;
int w[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d%d",&l,&n,&m,&d);
		m = min(m,l);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&w[i]);
		priority_queue<data> pq;
		for( int i = 0 ; i < n ; i++ )
			pq.push(newData(w[i],i));
		vector<LL> v;
		for( int i = 0 ; i < l ; i++ ) {
			data temp = pq.top();
			pq.pop();
			LL t = temp.t;
			int id = temp.id;
			v.pb(t);
			pq.push(newData(t+w[id],id));
		}
		priority_queue<data> heap;
		for( int i = 0 ; i < m ; i++ )
			heap.push(newData(v[i]+d,-1));
		for( int i = m ; i < l ; i++ ) {
			data temp = heap.top();
			heap.pop();
			LL t = max(temp.t,v[i]);
			heap.push(newData(t+d,-1));
		}
		LL ans;
		for( int i = 0 ; i < m ; i++ ) {
			ans = heap.top().t;
			heap.pop();
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
