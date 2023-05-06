#include <bits/stdc++.h>
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long LL;

int T,n;
int ar[maxn];
stack<int> st;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			ar[i] = abs(ar[i]) % 4;
		}
		for( int i = n-1 ; i >= 0 ; i-- )
			if(ar[i] % 2 == 0)
				st.push(i);
		int left = -1;
		LL ans = (LL) n * (n+1) / 2;
		for( int i = 0 ; i < n ; i++ ) {
			int right = n;
			if(!st.empty() && st.top() == i)
				st.pop();
			if(!st.empty())
				right = st.top();
			if(ar[i] == 2)
				ans -= (LL) (right-i) * (i-left);
			if(ar[i] % 2 == 0)
				left = i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
