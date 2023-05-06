#include <bits/stdc++.h>
using namespace std;

int T,n,total;
int cnt[4][4];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ ) {
			int inp0;
			string inp1;
			cin >> inp1 >> inp0;
			cnt[inp0/3-1][inp1[0]-'A']++;
		}
		int ans = -400;
		int perm[4] = {0,1,2,3};
		do {
			int sum = 0;
			int req[4] = {0,0,0,0};
			for( int i = 0 ; i < 4 ; i++ )
				req[i] = cnt[i][perm[i]];
			sort(req, req+4);
			for( int i = 0 ; i < 4 ; i++ ) {
				if( req[i] == 0 )
					sum -= 100;
				else
					sum += req[i] * 25 * (i+1);
			}
			ans = max(ans, sum);
		}while(next_permutation(perm, perm+4));
		printf("%d\n",ans);
		total += ans;
	}
	printf("%d\n",total);
	return 0;
}
