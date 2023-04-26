#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,m;
vector<int> v;

LL f(int i , int k , LL num) {
	if(i == k)
		return 1;
	LL res;
	if(num + (1LL << v[i]) <= n)
		res = f(i+1,k,num+(1LL<<v[i])) + (1LL<<(k-i-1));
	else
		res = f(i+1,k,num);
	return res;
}

int main() {
	scanf("%lld%lld",&n,&m);
	for( int i = 0 ; i < m ; i++ ) {
		LL t,x;
		scanf("%lld%lld",&t,&x);
		if(t == 1)
			printf("%d\n",(x<=n));
		else if(t == 2)
			printf("%lld\n",!x);
		else if(x == 0)
			printf("%lld\n",n+1);
		else {
			v.clear();
			for( int i = 33 ; i >= 0 ; i-- )
				if((x & (1LL << i)) == 0)
					v.push_back(i);
			printf("%lld\n",f(0,v.size(),0));
		}
	}
	return 0;
}
