#include <bits/stdc++.h>
#define se second
#define maxn 100003
using namespace std;
typedef long long LL;

LL n,x,m,ans;
LL res[maxn];
LL sum[maxn];
map<LL,int> idx;
map<LL,int>::iterator it;

int main() {
	scanf("%lld%lld%lld",&n,&x,&m);
	res[1] = sum[1] = x;
	idx[x] = 1;
	for( int i = 2 ; i <= n ; i++ ) {
		LL val = (res[i-1]*res[i-1])%m;
		it = idx.find(val);
		if(it == idx.end()) {
			idx[val] = i;
			res[i] = val;
			sum[i] = sum[i-1]+val;
		}
		else {
			int l = it->se;
			int r = i;
			LL ans = sum[l-1];
			int len = r-l;
			LL times = (n-(l-1))/len;
			int rem = (n-(l-1))%len;
			LL block = sum[r-1]-sum[l-1];
			ans += block*times;
			ans += sum[l-1+rem] - sum[l-1];
			printf("%lld\n",ans);
			exit(0);
		}
	}
	printf("%lld\n",sum[n]);
	return 0;
}
