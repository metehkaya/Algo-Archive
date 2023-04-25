// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
using namespace std;
typedef long long Lint;

const int maxn = 200020;

int a,p,b,tot;

Lint n;
map<Lint,Lint> mp;
Lint ans[maxn],cur[maxn];

Lint find( Lint n ) {
	if( !mp.count( n ) )
		return n;
	return mp[n] = find( mp[n] );
}

int main() {

	scanf("%lld %d %d",&n,&p,&a);
	for( int i = 1 ; i <= a ; i++ ) {
		int x, y, x1, y1;
		scanf("%d %d %d %d",&x,&y,&x1,&y1);
		Lint start = (Lint)(y-1)*n;
		if(y&1)
			start += x;
		else
			start += n-x+1;
		Lint finish = (Lint)(y1-1)*n;
		if(y1&1)
			finish += x1;
		else
			finish += n-x1+1;
		mp[start] = finish;
	}

	scanf("%d",&b);
	for( int i = 1 ; i <= b ; i++ ) {
		int x, y, x1, y1;
		scanf("%d %d %d %d",&x,&y,&x1,&y1);
		Lint start = (Lint)(y-1)*n;
		if(y&1)
			start += x;
		else
			start += n-x+1;
		Lint finish = (Lint)(y1-1)*n;
		if(y1&1)
			finish += x1;
		else
			finish += n-x1+1;
		mp[start] = finish;
	}

	tot = 0;
	int pl = 1;
	for( int i = 1 ; i <= p ; i++ )
		cur[i] = 0;

	int q;
	scanf("%d",&q);

	while( q-- ) {
		int x, y;
		scanf("%d %d",&x,&y);
		Lint val = x + y;
		cur[pl] = find( cur[pl] + val );
		if( cur[pl] > n*n ) {
			tot++;
			ans[pl] = 1;
			if( tot == p )
				break;
		}
		do {
			pl %= p;
			pl++;
		} while( ans[pl] == 1 );
	}

	for( int i = 1 ; i <= p ; i++ ) {
		if( ans[i] )
			printf("%d winner\n",i);
		else {
			if( cur[i] == 0 )
				printf("%d 0 1\n",i);
			else {
				Lint x, y = (cur[i]-1) / n + 1;
				if( y&1 )
					x = (cur[i]-1) % n + 1;
				else
					x = n - (cur[i]-1) % n;
				printf("%d %lld %lld\n",i,x,y);
			}
		}
	}

	return 0;

}
