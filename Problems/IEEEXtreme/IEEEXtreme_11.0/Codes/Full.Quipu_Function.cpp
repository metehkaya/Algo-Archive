#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define maxn 100001
#define maxs 1000001LL
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T;
LL a,b,d;
bool isBP[maxs];
bool mark[maxs];
int cntDiv[maxn];
vector<int> primes;
vector<pi> divPrimes[maxn];

void read() {
	scanf( "%d%lld%lld" , &T , &a , &b );
}

void findPrimes() {
	int s = min( b , maxs - 1 );
	for( int i = 2 ; i <= s ; i++ )
		if( !mark[i] ) {
			primes.pb( i );
			if( i <= s / i )
				for( int j = i * i ; j <= s ; j += i )
					mark[j] = true;
		}
}

void preCalc() {
	for( int i = 0 ; i < primes.size() ; i++ ) {
		LL x = a / primes[i];
		LL y = x * primes[i];
		if( y < a )
			y += primes[i];
		while( y <= b ) {
			divPrimes[y-a].pb( pi( primes[i] , 0 ) );
			y += primes[i];
		}
	}
	for( int i = 0 ; i <= b - a ; i++ ) {
		LL x = a + i;
		cntDiv[i] = 1;
		for( int j = 0 ; j < divPrimes[i].size() ; j++ ) {
			LL pr = divPrimes[i][j].fi;
			while( x % pr == 0 ) {
				divPrimes[i][j].se++;
				x /= pr;
			}
			cntDiv[i] *= divPrimes[i][j].se + 1;
		}
		if( x > 1 ) {
			cntDiv[i] *= 2;
			isBP[i] = true;
		}
	}
}

void print() {
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf( "%lld" , &d );
		int sum = 0;
		for( int i = 0 ; i <= b - a ; i++ ) {
			int divv = 1;
			for( int j = 0 ; j < divPrimes[i].size() && divPrimes[i][j].fi <= d ; j++ )
				if( divPrimes[i][j].fi == d ) {
					divv = divPrimes[i][j].se + 1;
					break;
				}
			if( d == a + i && isBP[i] )
				divv *= 2;
			sum += cntDiv[i] / divv;
		}
		printf( "%d\n" , sum );
	}
}

int main() {
	read();
	findPrimes();
	preCalc();
	print();
	return 0;
}
