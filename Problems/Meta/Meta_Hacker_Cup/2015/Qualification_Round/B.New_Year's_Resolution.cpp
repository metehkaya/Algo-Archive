#include <bits/stdc++.h>
#define maxn 20
using namespace std;

int T,n;
int t[3];
int curr[3];
int ar[maxn][3];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

bool f(int i) {
	if(i == n) {
		bool res = true;
		for( int j = 0 ; j < 3 ; j++ )
			res = res && (curr[j] == t[j]);
		return res;
	}
	if(f(i+1))
		return true;
	for( int j = 0 ; j < 3 ; j++ )
		curr[j] += ar[i][j];
	if(f(i+1))
		return true;
	for( int j = 0 ; j < 3 ; j++ )
		curr[j] -= ar[i][j];
	return false;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d%d",&t[0],&t[1],&t[2],&n);
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < 3 ; j++ )
				scanf("%d",&ar[i][j]);
		memset(curr,0,sizeof(curr));
		bool ans = f(0);
		string res = ans ? "yes" : "no";
		printf("Case #%d: %s\n",tc,res.c_str());
	}
	return 0;
}
