#include <bits/stdc++.h>
#define maxn 1003
using namespace std;
typedef long long LL;

LL ans;
int m,n;
int ar[maxn];
char s[maxn];

void maxArea() {
	stack<int> st;
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
}

int main() {
	scanf("%d%d",&m,&n);
	for( int i = 0 ; i < m ; i++ ) {
		scanf("%s",s);
		for( int j = 0 ; j < n ; j++ )
			if(s[j] == '.')
				ar[j]++;
			else
				ar[j] = 0;
		maxArea();
	}
	printf("%lld\n",ans);
	return 0;
}