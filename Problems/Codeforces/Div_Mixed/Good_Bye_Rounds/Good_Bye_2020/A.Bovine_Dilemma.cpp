#include <bits/stdc++.h>
using namespace std;

int T,n;
int x[50];
bool var[50];

int main() {
	scanf("%d",&T);
	for( int tc = 0 ; tc < T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&x[i]);
		int ans = 0;
		memset(var,false,sizeof(var));
		for( int i = 0 ; i < n ; i++ )
			for( int j = i+1 ; j < n ; j++ ) {
				ans += !var[x[j]-x[i]];
				var[x[j]-x[i]] = true;
			}
		printf("%d\n",ans);
	}
	return 0;
}
