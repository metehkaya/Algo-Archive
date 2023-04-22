#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
typedef long long LL;

LL ans;
int T,n,k;
LL s[maxn];
LL x[maxn];
LL y[maxn];
int as,bs,cs,ds;
int ax,bx,cx,dx;
int ay,by,cy,dy;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void input() {
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%d",&s[i]);
	scanf("%d%d%d%d",&as,&bs,&cs,&ds);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%d",&x[i]);
	scanf("%d%d%d%d",&ax,&bx,&cx,&dx);
	for( int i = 1 ; i <= k ; i++ )
		scanf("%d",&y[i]);
	scanf("%d%d%d%d",&ay,&by,&cy,&dy);
	for( int i = k+1 ; i <= n ; i++ ) {
		s[i] = (LL) as * s[i-2] + (LL) bs * s[i-1] + (LL) cs;
		s[i] %= ds;
	}
	for( int i = k+1 ; i <= n ; i++ ) {
		x[i] = (LL) ax * x[i-2] + (LL) bx * x[i-1] + (LL) cx;
		x[i] %= dx;
	}
	for( int i = k+1 ; i <= n ; i++ ) {
		y[i] = (LL) ay * y[i-2] + (LL) by * y[i-1] + (LL) cy;
		y[i] %= dy;
	}
	for( int i = 1 ; i <= n ; i++ )
		y[i] += x[i];
}

void solve() {
	LL sumLess1 = 0 , sumLess2 = 0;
	LL sumMore1 = 0 , sumMore2 = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		if(s[i] < x[i]) {
			sumLess1 += x[i]-s[i];
			sumLess2 += y[i]-s[i];
		}
		else if(y[i] < s[i]) {
			sumMore1 += s[i]-y[i];
			sumMore2 += s[i]-x[i];
		}
		else {
			sumLess2 += y[i]-s[i];
			sumMore2 += s[i]-x[i];
		}
	}
	ans = max(sumLess1,sumMore1);
	if(sumLess2 < sumMore1 || sumMore2 < sumLess1)
		ans = -1;
}

void output(int tc) {
	printf("Case #%d: %lld\n",tc,ans);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		input();
		solve();
		output(tc);
	}
	return 0;
}
