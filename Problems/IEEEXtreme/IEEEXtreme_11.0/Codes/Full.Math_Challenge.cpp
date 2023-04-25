#include <bits/stdc++.h>
#define maxn 1000001LL
#define mod 1000000007LL
using namespace std;
typedef long long LL;

LL T;
LL fact[maxn];
LL tot[maxn][2];
LL mods[2] = { 2 , 500000003 };

LL getPow( LL x , LL y , LL MOD ) {
	if( y == 0 )
		return 1;
	LL tmp = getPow( x , y / 2 , MOD );
	tmp = ( tmp * tmp ) % MOD;
	if( y & 1 )
		tmp = ( tmp * x ) % MOD;
	return tmp;
}

LL getComb( LL x , LL y , LL MOD ) {
	
	LL cnt[2];
	cnt[0] = tot[x][0] - tot[y][0] - tot[x-y][0];
	cnt[1] = tot[x][1] - tot[y][1] - tot[x-y][1];
	
	if( cnt[0] >= 1 && cnt[1] >= 1 )
		return 0;
	
	LL p = fact[x];
	LL q = ( fact[y] * fact[x-y] ) % MOD;
	
	q = getPow( q , MOD / 2 - 2 , MOD );
	
	LL res = ( p * q ) % MOD;
	
	res = ( res * getPow( mods[0] , cnt[0] , MOD ) ) % MOD;
	res = ( res * getPow( mods[1] , cnt[1] , MOD ) ) % MOD;
	
	return res;
	
}

int main() {
	
	fact[0] = 1;
	for( LL i = 1 ; i < maxn ; i++ ) {
		LL rem = i;
		LL cnt[2] = {0 , 0};
		for( int j = 0 ; j < 2 ; j++ )
			while( rem % mods[j] == 0 ) {
				cnt[j]++;
				rem /= mods[j];
			}
		for( int j = 0 ; j < 2 ; j++ )
			tot[i][j] = tot[i-1][j] + cnt[j];
		fact[i] = ( fact[i-1] * rem ) % ( mod - 1 );
	}
	
	scanf( "%lld" , &T );
	for( LL i = 0 , a , b , c ; i < T ; i++ ) {
		scanf( "%lld%lld%lld" , &a , &b , &c );
		LL ppow = getComb( b , c , mod - 1 );
		printf( "%lld\n" , getPow( a , ppow , mod ) );
	}
	
	return 0;

}
