#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n;
priority_queue<int> heap;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			heap.push(i);
		vector<pi> v;
		for( int i = 1 ; i < n ; i++ ) {
			int x = heap.top();
			heap.pop();
			int y = heap.top();
			heap.pop();
			v.pb(pi(x,y));
			heap.push((x+y+1)/2);
		}
		printf("%d\n",heap.top());
		for( int i = 1 ; i < n ; i++ )
			printf("%d %d\n",v[i-1].fi,v[i-1].se);
		heap.pop();
	}
	return 0;
}
