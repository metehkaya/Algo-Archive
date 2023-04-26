#include <bits/stdc++.h>
#define maxn 200001
using namespace std;

int n,m;
bool s[maxn];
bool e[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , x , y ; i < m ; i++ ) {
		scanf("%d%d",&x,&y);
		if(x == 1)
			s[y] = true;
		if(y == n)
			e[x] = true;
	}
	bool ans = false;
	for( int i = 1 ; i <= n ; i++ )
		if(s[i] && e[i])
			ans = true;
	if(ans)
		puts("POSSIBLE");
	else
		puts("IMPOSSIBLE");
	return 0;
}
