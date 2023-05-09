#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T;
LL X[4];
LL Y[4];
LL n,m,x,y;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> m >> x >> y;
		X[0] = 1 , Y[0] = 1;
		X[1] = 1 , Y[1] = m;
		X[2] = n , Y[2] = 1;
		X[3] = n , Y[3] = m;
		LL maxd = -1;
		pi ans;
		for( int i = 0 ; i < 4 ; i++ )
			for( int j = i+1 ; j < 4 ; j++ ) {
				LL xmin = min(x,min(X[i],X[j]));
				LL xmax = max(x,max(X[i],X[j]));
				LL ymin = min(y,min(Y[i],Y[j]));
				LL ymax = max(y,max(Y[i],Y[j]));
				LL dist = 2*(xmax-xmin+ymax-ymin);
				if(dist > maxd) {
					maxd = dist;
					ans = pi(i,j);
				}
			}
		printf("%lld %lld %lld %lld\n",X[ans.fi],Y[ans.fi],X[ans.se],Y[ans.se]);
	}
	return 0;
}
