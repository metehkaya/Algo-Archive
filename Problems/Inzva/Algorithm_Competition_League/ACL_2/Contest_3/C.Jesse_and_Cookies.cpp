#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,k,ans;
priority_queue< LL,vector<LL>,greater<LL> > pq;

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		pq.push(x);
	}
	while(n > 1 && pq.top() < k) {
		n--;
		ans++;
		LL x = pq.top();
		pq.pop();
		LL y = pq.top();
		pq.pop();
		pq.push(x+2*y);
	}
	if(pq.top() >= k)
		printf("%d\n",ans);
	else
		puts("-1");
	return 0;
}
