#include <bits/stdc++.h>
#define maxn 50001
using namespace std;

int T,n;
int ar[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

bool f(int i , int l , int r) {
	deque<int> Q;
	Q.push_back(ar[i]);
	while(l <= r) {
		int s = Q.front();
		int e = Q.back();
		if(ar[l] == s-1)
			Q.push_front(ar[l++]);
		else if(ar[l] == e+1)
			Q.push_back(ar[l++]);
		else if(ar[r] == s-1)
			Q.push_front(ar[r--]);
		else if(ar[r] == e+1)
			Q.push_back(ar[r--]);
		else
			return false;
	}
	return true;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		bool ans = f(1,2,n) || f(n,1,n-1);
		string res = ans ? "yes" : "no";
		printf("Case #%d: %s\n",tc,res.c_str());
	}
	return 0;
}
