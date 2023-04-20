#include <bits/stdc++.h>
#define maxn 200001
using namespace std;

int n;
int ar[maxn];
stack<int> st;

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		while(!st.empty() && ar[st.top()] >= ar[i])
			st.pop();
		if(st.empty())
			printf("0 ");
		else
			printf("%d ",st.top());
		st.push(i);
	}
	return 0;
}