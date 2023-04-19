#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long LL;

struct point {
	LL a,b,c,d,e,f;
} p[maxn];

int n,m,q;
int x[maxn];
int y[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d%d",&x[i],&y[i]);
	scanf("%d",&m);
	p[0].a = p[0].e = 1;
	p[0].b = p[0].c = p[0].d = p[0].f = 0;
	for( int i = 1 , t ; i <= m ; i++ ) {
		scanf("%d",&t);
		if(t == 1) {
			p[i].a = p[i-1].d;
			p[i].b = p[i-1].e;
			p[i].c = p[i-1].f;
			p[i].d = -p[i-1].a;
			p[i].e = -p[i-1].b;
			p[i].f = -p[i-1].c;
		}
		else if(t == 2) {
			p[i].a = -p[i-1].d;
			p[i].b = -p[i-1].e;
			p[i].c = -p[i-1].f;
			p[i].d = p[i-1].a;
			p[i].e = p[i-1].b;
			p[i].f = p[i-1].c;
		}
		else if(t == 3) {
			LL k;
			scanf("%lld",&k);
			p[i].a = -p[i-1].a;
			p[i].b = -p[i-1].b;
			p[i].c = 2*k - p[i-1].c;
			p[i].d = p[i-1].d;
			p[i].e = p[i-1].e;
			p[i].f = p[i-1].f;
		}
		else {
			LL k;
			scanf("%lld",&k);
			p[i].a = p[i-1].a;
			p[i].b = p[i-1].b;
			p[i].c = p[i-1].c;
			p[i].d = -p[i-1].d;
			p[i].e = -p[i-1].e;
			p[i].f = 2*k - p[i-1].f;
		}
	}
	scanf("%d",&q);
	for( int i = 0 , a,b ; i < q ; i++ ) {
		scanf("%d%d",&a,&b);
		LL xx = p[a].a*x[b] + p[a].b*y[b] + p[a].c;
		LL yy = p[a].d*x[b] + p[a].e*y[b] + p[a].f;
		printf("%lld %lld\n",xx,yy);
	}
	return 0;
}
