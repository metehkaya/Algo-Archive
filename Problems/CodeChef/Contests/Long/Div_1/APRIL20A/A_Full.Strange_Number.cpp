#include <bits/stdc++.h>
#define maxs 32000
#define pb push_back
using namespace std;

int T,n,k;
bool isNotPrime[maxs];
vector<int> primes;

int main() {
	for( int i = 2 ; i < maxs ; i++ )
		if(!isNotPrime[i]) {
			primes.pb(i);
			for( int j = i*i ; j < maxs ; j += i )
				isNotPrime[j] = true;
		}
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&k);
		int cnt = 0;
		for( int i = 0 ; i < (int) primes.size() ; i++ )
			while(n % primes[i] == 0) {
				cnt++;
				n /= primes[i];
			}
		if(n > 1)
			cnt++;
		if(cnt >= k)
			puts("1");
		else
			puts("0");
	}
	return 0;
}
