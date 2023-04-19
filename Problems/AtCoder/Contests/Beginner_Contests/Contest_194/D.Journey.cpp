#include <bits/stdc++.h>
using namespace std;

int n;
double ans;

int main() {
	scanf("%d",&n);
	for( int i = n-1 ; i >= 1 ; i-- )
		ans += (double) n / (n-i);
	printf("%.7lf\n",ans);
	return 0;
}
