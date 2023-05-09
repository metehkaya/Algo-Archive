#include <bits/stdc++.h>
#define maxn 300005
using namespace std;

int n;
int ar[maxn];
int ans[maxn];
stack<int> st[2];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	st[0].push(n);
	st[1].push(n);
	for( int i = n-1 ; i >= 1 ; i-- ) {
		ans[i] = INT_MAX;
		bool isSame;
		isSame = false;
		while(!st[0].empty() && ar[i] >= ar[st[0].top()]) {
			int idx = st[0].top();
			ans[i] = min(ans[i],ans[idx]+1);
			if(ar[i] == ar[idx])
				isSame = true;
			st[0].pop();
		}
		if(!st[0].empty() && !isSame) {
			int idx = st[0].top();
			ans[i] = min(ans[i],ans[idx]+1);
		}
		isSame = false;
		while(!st[1].empty() && ar[i] <= ar[st[1].top()]) {
			int idx = st[1].top();
			ans[i] = min(ans[i],ans[idx]+1);
			if(ar[i] == ar[idx])
				isSame = true;
			st[1].pop();
		}
		if(!st[1].empty() && !isSame) {
			int idx = st[1].top();
			ans[i] = min(ans[i],ans[idx]+1);
		}
		st[0].push(i);
		st[1].push(i);
	}
	printf("%d\n",ans[1]);
	return 0;
}
