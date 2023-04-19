#include <bits/stdc++.h>
#define maxn 10000
using namespace std;

int n;
int ar[maxn];
stack<int> S;

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	int ans = 0;
	for( int i = 0 ; i < n ; i++ ) {
		while(!S.empty() && ar[i] < ar[S.top()]) {
			int val = ar[S.top()];
			S.pop();
			int index = S.empty() ? -1 : S.top();
			ans = max( ans , val * (i-1-index) );
		}
		S.push(i);
	}
	while(!S.empty()) {
		int val = ar[S.top()];
		S.pop();
		int index = S.empty() ? -1 : S.top();
		ans = max( ans , val * (n-1-index) );
	}
    printf("%d\n",ans);
	return 0;
}
