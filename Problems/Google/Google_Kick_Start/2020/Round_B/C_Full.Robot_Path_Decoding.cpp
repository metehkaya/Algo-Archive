#include <bits/stdc++.h>
#define fi first
#define se second
#define mod (int)1e9
#define maxn 2003
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n;
int nxt[maxn];
char str[maxn];
stack<int> st;

pi getDir(char c) {
	if(c == 'E')
		return pi(1,0);
	else if(c == 'W')
		return pi(mod-1,0);
	else if(c == 'S')
		return pi(0,1);
	else
		return pi(0,mod-1);
}

pi add(pi a, pi b) {
	return pi( (a.fi + b.fi) % mod , (a.se + b.se) % mod );
}

pi mult(pi a, int k) {
	return pi( (LL) k * a.fi % mod , (LL) k * a.se % mod );
}

pi f(int l, int r) {
	if(l > r)
		return pi(0,0);
	char c = str[l];
	pi left, right;
	if(c >= '2' && c <= '9') {
		int index = nxt[l+1];
		left = mult( f(l+2, index-1) , c-'0' );
		right = f(index+1, r);
	}
	else {
		left = getDir(c);
		right = f(l+1, r);
	}
	return add(left, right);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s",str);
		n = strlen(str);
		for( int i = 0 ; i < n ; i++ ) {
			if( str[i] == '(' )
				st.push(i);
			else if(str[i] == ')') {
				nxt[st.top()] = i;
				st.pop();
			}
		}
		pi ans = f(0, n-1);
		printf("Case #%d: %d %d\n",tc,ans.fi+1,ans.se+1);
	}
	return 0;
}
