#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
char s[13][13];

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ )
		scanf("%s",s[i]);
	for( int i = 0 ; i < n-1 ; i++ )
		for( int j = 0 ; j < m-1 ; j++ ) {
			int cnt = 0;
			cnt += (s[i][j] == s[i][j+1]);
			cnt += (s[i][j] == s[i+1][j]);
			cnt += (s[i][j] == s[i+1][j+1]);
			ans += (cnt == 0 || cnt == 2);
		}
	printf("%d\n",ans);
	return 0;
}
