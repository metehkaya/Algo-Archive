#include <bits/stdc++.h>
using namespace std;

int T,n;
char str[103];
int sum[103][26];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s",str+1);
		n = strlen(str+1);
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 0 ; j < 26 ; j++ )
				sum[i][j] = sum[i-1][j] + (str[i] == 'a' + j);
		int ans = 0;
		for( int len = 1 ; len < n ; len++ )
			for( int i = len ; i < n ; i++ )
				for( int j = i+1 ; j <= n ; j++ ) {
					bool ok = true;
					for( int k = 0 ; ok && k < 26 ; k++ )
						if( sum[i][k]-sum[i-len][k] != sum[j][k]-sum[j-len][k] )
							ok = false;
					ans += ok;
				}
		printf("%d\n",ans);
	}
}
