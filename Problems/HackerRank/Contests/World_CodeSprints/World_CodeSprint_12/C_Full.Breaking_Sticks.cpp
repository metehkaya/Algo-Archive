#include <bits/stdc++.h>
#define maxn 1000001
#define pb push_back
using namespace std;
typedef long long LL;

int n;
LL ans;
bool mark[maxn];
vector<LL> v;
vector<int> primes;

void f(LL numb , int id , LL cnt) {
	if(id == -1)
		return;
	LL val = v[id];
	ans += cnt;
	f( numb/val,id-1,cnt*val);
}

int main() {
	primes.pb(2);
	for( int i = 3 ; i < maxn ; i += 2 )
		if(!mark[i]) {
			primes.pb(i);
			if(i <= maxn/i)
				for( int j = i*i ; j < maxn ; j += i )
					mark[j] = true;
		}
	scanf("%d",&n);
	LL x;
	for( int tc = 0  ; tc < n ; tc++ ) {
		scanf("%lld",&x);
		LL tmp = x;
		v.clear();
		for( int i = 0 ; i < primes.size() ; i++ )
			while(tmp % primes[i] == 0) {
				tmp /= primes[i];
				v.pb(primes[i]);
			}
		if(tmp > 1)
			v.pb(tmp);
		ans += x;
		f(x,v.size()-1,1);
	}
	printf("%lld\n",ans);
	return 0;
}
