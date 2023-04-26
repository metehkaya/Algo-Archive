#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,m;

int main() {
	scanf("%lld%lld",&m,&n);
	printf("%lld\n",(n/m)+((n%m)>0));
	return 0;
}
