#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL curr;
int n,ans;
priority_queue<LL> heap;

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		LL x,y;
		cin >> x >> y;
		curr -= x;
		heap.push(2*x+y);
	}
	while(curr <= 0) {
		LL add = heap.top();
		heap.pop();
		ans++;
		curr += add;
	}
	printf("%d\n",ans);
	return 0;
}
