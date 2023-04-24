#include <bits/stdc++.h>
#define maxn 10000
using namespace std;
typedef long long LL;

int T,n,k;
LL ar[maxn];
map<LL,int> hashCnt;

int main() {
	cin >> T;
	for( int tc = 1 ; tc <= T ; tc++ ) {
		hashCnt.clear();
		cin >> n >> k;
		int mxCnt = 0;
		for( int i = 0 ; i < n ; i++ ) {
			cin >> ar[i];
			mxCnt = max( mxCnt , ++hashCnt[ar[i]] );
		}
		int ans = -1;
		sort( ar , ar+n );
		if(k == 2) {
			if(mxCnt >= 2)
				ans = 0;
			else
				ans = 1;
		}
		else if(k == 3) {
			if(mxCnt >= 3)
				ans = 0;
			else {
				ans = 2;
				for( int i = 0 ; i < n ; i++ ) {
					LL val = ar[i];
					if(hashCnt.find(2*val) != hashCnt.end()) {
						ans = 1;
						break;
					}
				}
				for( int i = 1 ; i < n-1 ; i++ )
					if( ar[i] == ar[i-1] && hashCnt[ar[i]] == 2 ) {
						ans = 1;
						break;
					}
			}
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;	
}
