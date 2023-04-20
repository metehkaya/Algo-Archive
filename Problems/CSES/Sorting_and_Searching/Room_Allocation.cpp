#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200000
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int n,k;
int ans[maxn];
pii ar[2*maxn];
queue<int> Q;

int main() {
	scanf("%d",&n);
	for( int i = 0 , s , e ; i < n ; i++ ) {
		scanf("%d%d",&s,&e);
		ar[2*i] = pii( pi( s , 0 ) , i );
		ar[2*i+1] = pii( pi( e , 1 ) , i );
	}
	sort(ar,ar+2*n);
	for( int i = 0 ; i < 2*n ; i++ ) {
		int t = ar[i].fi.fi;
		int type = ar[i].fi.se;
		int id = ar[i].se;
		if(type == 0) {
			if(Q.empty())
				ans[id] = ++k;
			else {
				ans[id] = Q.front();
				Q.pop();
			}
		}
		else
			Q.push(ans[id]);
	}
	printf("%d\n",k);
	for( int i = 0 ; i < n ; i++ )
		printf("%d ",ans[i]);
	return 0;
}