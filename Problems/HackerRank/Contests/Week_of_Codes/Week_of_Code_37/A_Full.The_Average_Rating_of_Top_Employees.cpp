#include <bits/stdc++.h>
using namespace std;

int n,sum,cnt;

int main() {
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		if(x >= 90) {
			sum += x;
			cnt++;
		}
	}
	double tmp = 1000.0*sum/cnt;
	int tmpi = tmp;
	int mod10 = tmpi % 10;
	if(mod10 < 5)
		printf("%.2lf\n",(tmpi-mod10)/1000.0);
	else
		printf("%.2lf\n",(tmpi-mod10+10)/1000.0);
	return 0;
}
