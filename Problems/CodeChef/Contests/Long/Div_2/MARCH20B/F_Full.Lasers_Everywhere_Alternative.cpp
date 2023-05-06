#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

const double R = 0.5;

int T,n,m,k,q;
vector<pi>Q;

void solve23() {
	vector<int> ans;
	for( int i = 0 , res ; i < q ; i++ ) {
		int y = (int) max( m*R , 1.0 );
		printf("1 %d %d %d\n",Q[i].fi,Q[i].se,y);
		fflush(stdout);
		scanf("%d",&res);
		ans.pb(res);
	}
	printf("2");
	for( int i = 0 ; i < q ; i++ )
		printf(" %d", ans[i]);
	puts("");
	fflush(stdout);
}

void solve1() {
	printf("2");
	for( int i = 0 ; i < q ; i++ )
		printf(" %d", m-1);
	puts("");
	fflush(stdout);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 , correct ; tc <= T ; tc++ ) {
		Q.clear();
		scanf("%d%d%d%d",&n,&m,&k,&q);
		for( int i = 0 , x,y ; i < q ; i++ ) {
			scanf("%d%d",&x,&y);
			Q.pb(pi(x,y));
		}
		if(k == 3)
			solve1();
		else
			solve23();
		scanf("%d",&correct);
		if(correct == -1)
			break;
	}
	return 0;
}
