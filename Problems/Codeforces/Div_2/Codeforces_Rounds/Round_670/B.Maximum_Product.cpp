#include <bits/stdc++.h>
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;

LL ans;
int T,n;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		ans = -(1LL << 60);
		vector<int> pos,neg;
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&ar[i]);
			if(ar[i] == 0)
				ans = 0;
			else if(ar[i] > 0)
				pos.pb(ar[i]);
			else
				neg.pb(-ar[i]);
		}
		int np = pos.size();
		int nn = neg.size();
		sort(pos.begin(),pos.end());
		sort(neg.begin(),neg.end());
		LL res1 = 1 , res2 = 1;
		for( int i = 0 ; i <= min(np,5) ; i++ ) {
			if(i) {
				res1 *= pos[i-1];
				res2 *= pos[np-i];
			}
			if(nn >= 5-i) {
				LL a = res1 , b = res1 , c = res2 , d = res2;
				for( int j = 0 ; j < 5-i ; j++ ) {
					a *= -neg[j];
					b *= -neg[nn-1-j];
					c *= -neg[j];
					d *= -neg[nn-1-j];
				}
				ans = max(ans,a);
				ans = max(ans,b);
				ans = max(ans,c);
				ans = max(ans,d);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
