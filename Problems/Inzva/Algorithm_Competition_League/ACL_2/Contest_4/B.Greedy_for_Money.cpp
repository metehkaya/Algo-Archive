#include <bits/stdc++.h>
using namespace std;

int n,cnt;
priority_queue<int> pq;

int main() {
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		pq.push(x);
	}
	while(pq.top() + cnt >= n) {
		int x = pq.top();
		pq.pop();
		int k = (x+cnt) / n;
		cnt += k;
		x -= k*(n+1);
		pq.push(x);
	}
	printf("%d\n",cnt);
	return 0;
}
