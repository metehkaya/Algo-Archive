#include <bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long LL;

int n;
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	stack<int> st;
	LL ans = 0;
	for( int i = 0 ; i < n ; i++ ) {
		while(!st.empty() && ar[i] < ar[st.top()]) {
			int val = ar[st.top()];
			st.pop();
			int index = st.empty() ? -1 : st.top();
			ans = max( ans , (LL) val * (i-1-index) );
		}
		st.push(i);
	}
	while(!st.empty()) {
		int val = ar[st.top()];
		st.pop();
		int index = st.empty() ? -1 : st.top();
		ans = max( ans , (LL) val * (n-1-index) );
	}
	printf("%lld\n",ans);
	return 0;
}