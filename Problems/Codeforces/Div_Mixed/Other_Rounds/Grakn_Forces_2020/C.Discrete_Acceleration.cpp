#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

const double EPS = 1e-6;

int T,n,l;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&l);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		double ans = 0;
		double x1 = 0 , x2 = l;
		double s1 = 1 , s2 = 1;
		for( int i = 1 , j = n ; i <= j ; ) {
			double t1 = (ar[i] - x1) / s1;
			double t2 = (x2 - ar[j]) / s2;
			if(fabs(t1-t2) < EPS) {
				i++;
				j--;
				ans += t1;
				x1 += t1*s1;
				x2 -= t1*s2;
				s1 += 1;
				s2 += 1;
			}
			else if(t1 < t2) {
				i++;
				ans += t1;
				x1 += t1*s1;
				x2 -= t1*s2;
				s1 += 1;
			}
			else {
				j--;
				ans += t2;
				x1 += t2*s1;
				x2 -= t2*s2;
				s2 += 1;
			}
		}
		ans += (x2-x1) / (s1+s2);
		printf("%lf\n",ans);
	}
	return 0;
}
