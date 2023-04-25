// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 200020;

int a,last,cnt;
int ar[maxn],ans[maxn];
vector<int> v;

int que() {
	++cnt;
	printf("Q ");
	for( int i = 1 ; i <= a ; i++ )
		printf("%d ",ar[i]);
	printf("\n");
	fflush( stdout );
	int x;
	scanf("%d",&x);
	return x;
}

int get( int x, int y ) {
	ar[x] ^= 1;
	ar[y] ^= 1;
	int ans = que() - last;
	ar[x] ^= 1;
	ar[y] ^= 1;
	return ans;
}

void solve() {
	scanf("%d",&a);
	cnt = 0;
	v.clear();
	for( int i = 1 ; i <= a ; i++ )
		ar[i] = ans[i] = 0;
	last = que();
	for( int i = 1 ; i <= a ; i++ )
		v.pb( i );
    int t;
	for( int i = 0 ; i < v.size() ; i++ ) {
		int j = i , h;
		while( j+1 < v.size() && ( h = get( v[j], v[j+1] ) ) == 0 ) {
			j++;
			t = 0;
		}
		if( j == v.size()-1 ) {
			h = get( v[j], 0 );
			if( h == 1 )
				ans[ v[j] ] = 1;
		}
		else if( h == 2 ) {
			ans[ v[j] ] = 1;
			ans[ v[j+1] ] = 1;
		}
		for(int k = j-1 ; k >= i ; k-- )
			ans[ v[k] ] = !ans[ v[k+1] ];
		i = j+1;
	}

	printf("A ");
	for( int i = 1 ; i <= a ; i++ )
		printf("%d ",ans[i]);
	printf("\n");
	fflush( stdout );
}

int main() {
	srand( time(0) );
	int n = 1;
	scanf("%d",&n);
	while(n--)
		solve();
	return 0;
}
