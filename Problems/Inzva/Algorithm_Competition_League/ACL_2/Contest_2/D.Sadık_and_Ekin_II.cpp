#include <bits/stdc++.h>
#define maxn 100001
using namespace std;

int n,k,cnt;
int ar[maxn];
bool mark[maxn];
bool isNotP[maxn];
vector<int> primes;

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 2 ; i <= k ; i++ )
		if(!isNotP[i]) {
			primes.push_back(i);
			if(i <= k/i)
				for( int j = i*i ; j <= k ; j += i )
					isNotP[j] = true;
		}
	for( int i = 1 , num ; i <= n ; i++ ) {
		scanf("%d",&num);
		int x = num;
		for( int j = 0 ; primes[j]*primes[j] <= num ; j++ )
			if(x%primes[j] == 0) {
				while(x%primes[j] == 0)
					x /= primes[j];
				cnt += !mark[primes[j]];
				mark[primes[j]] = true;
			}
		if(x>1) {
			cnt += !mark[x];
			mark[x] = true;
		}
	}
	if(cnt == 1 || primes.size()%2 == 1)
		puts("SADIK");
	else
		puts("EKIN");
	return 0;
}
