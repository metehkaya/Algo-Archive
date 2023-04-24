#include <bits/stdc++.h>
#define maxq 1200
#define maxs 10001
#define maxn 50000
#define pb push_back
using namespace std;

int n,q,p;
int ar[maxn];
int rev[maxs];
bool notPrime[maxs];
vector<int> rem;
vector<int> primes;
vector<int> v[maxq];

void read() {
	scanf("%d%d",&n,&q);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
}

void f( int val , int index , int prime ) {
	if(index == p || val * primes[index] >= maxs) {
		if(prime != -1)
			rev[val] = prime;
		return;
	}
	f(val,index+1,prime);
	while(true) {
		val *= primes[index];
		if(val >= maxs)
			break;
		if(prime != -1)
			f(val,index+1,prime);
		else
			f(val,index+1,index);
	}
}

void preCalc() {
	for( int i = 2 ; i < maxs ; i++ )
		if(!notPrime[i]) {
			primes.pb( i );
			for( int j = i*i ; j < maxs ; j += i )
			    notPrime[j] = true;
		}
	p = primes.size();
	f(1,0,-1);
}

void solve() {
	for( int i = 0 ; i < n ; i++ ) {
		int k = rev[ ar[i] ];
		if(k >= q) {
			rem.pb(ar[i]);
			continue;
		}
		v[k].pb(ar[i]);
	}
	int sz;
	for( int i = 0 ; i < q ; i++ ) {
		sz = v[i].size();
		if(i % 2 == 0)
			for( int j = 0 ; j < sz ; j++ )
				printf("%d\n",v[i][j]);
		if(i % 2 == 1)
			for( int j = sz - 1 ; j >= 0 ; j-- )
				printf("%d\n",v[i][j]);
	}
	sz = rem.size();
	if(q % 2 == 1)
		for( int i = 0 ; i < sz ; i++ )
			printf("%d\n",rem[i]);
	if(q % 2 == 0)
		for( int i = sz - 1 ; i >= 0 ; i-- )
			printf("%d\n",rem[i]);
}

int main() {
	read();
	preCalc();
	solve();
	return 0;
}
