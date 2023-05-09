#include <bits/stdc++.h>
#define maxn 3001
using namespace std;
typedef long long LL;

int T,n;
int ar[maxn];
int cnt[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ ) {
			cnt[i] = 0;
			scanf("%d",&ar[i]);
		}
		LL ans = 0;
		for( int j = n-1 ; j >= 3 ; j-- ) {
			int add = 0;
			cnt[ar[j+1]]++;
			for( int i = j-2 ; i >= 1 ; i-- ) {
				int val = ar[i+1];
				add += cnt[val];
				if(ar[i] == ar[j])
					ans += add;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
