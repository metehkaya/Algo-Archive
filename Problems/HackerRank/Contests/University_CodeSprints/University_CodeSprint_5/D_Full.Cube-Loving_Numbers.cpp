#include <bits/stdc++.h>
#define maxs 1000001
#define pb push_back
using namespace std;
typedef long long LL;

int T,p;
LL n,ans;
bool notPrime[maxs];
int cntPrimes[maxs];
vector<int> pr;

void f(int value , int last , int cnt) {
	cntPrimes[value] = cnt;
	for( int i = last+1 ; i < p && value <= maxs/pr[i] ; i++ ) {
		if(value * pr[i] >= maxs)
			break;
		f(value*pr[i],i,cnt+1);
	}
}

int main() {
	for( int i = 2 ; i < maxs ; i++ )
		if(!notPrime[i]) {
			pr.pb(i);
			if(i <= maxs/i)
				for( int j = i*i ; j < maxs ; j += i )
					notPrime[j] = true;
		}
	p = pr.size();
	f(1,-1,0);
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%lld",&n);
		ans = 0;
		for( LL i = 2 ; i * i * i <= n ; i++ )
			if(cntPrimes[i]) {
				LL val = n / (i*i*i);
				if(cntPrimes[i] % 2)
					ans += val;
				else
					ans -= val;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
