#include <bits/stdc++.h>
#define maxn 200003
using namespace std;

int T,n,m,l,u,r,d;
double lfact[maxn];

int main() {
	for( int i = 2 ; i < maxn ; i++ )
		lfact[i] = lfact[i-1] + log2((double)i);
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d%d%d%d",&m,&n,&l,&u,&r,&d);
		double ans = 0.0;
		if(d < n && l > 1)
			for( int i = l-1 ; i >= 1 ; i-- ) {
				int k = i-1;
				int step = l+d-2;
				double pwr = lfact[step]-lfact[k]-lfact[step-k]-step;
				ans += pow(2.0, pwr);
			}
		if(u > 1 && r < m)
			for( int i = u-1 ; i >= 1 ; i-- ) {
				int k = i-1;
				int step = u+r-2;
				double pwr = lfact[step]-lfact[k]-lfact[step-k]-step;
				ans += pow(2.0, pwr);
			}
		printf("Case #%d: %lf\n",tc,ans);
	}
	return 0;
}
