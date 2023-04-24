#include <bits/stdc++.h>
#define maxn 400003
using namespace std;
typedef long long LL;

struct data {
	int type,pos,id;
} ar[maxn];

data getData(int _type , int _pos , int _id) {
	data tmp;
	tmp.type = _type;
	tmp.pos = _pos;
	tmp.id = _id;
	return tmp;
}

bool comp(data f , data s) {
	if( f.pos != s.pos )
		return f.pos < s.pos;
	return f.type < s.type;
}

LL ans;
int n,m,k;
int p[maxn];
int x[maxn];
int y[maxn];
int r[maxn];
int open[maxn];
int close[maxn];
LL sum[2][maxn];

void input() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&p[i]);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&x[i]);
	scanf("%d",&m);
	for( int i = 1 ; i <= m ; i++ )
		scanf("%d",&y[i]);
	for( int i = 1 ; i <= m ; i++ )
		scanf("%d",&r[i]);
}

void solve() {
	for( int i = 1 ; i <= n ; i++ )
		ar[++k] = getData(1,x[i],i);
	for( int i = 1 ; i <= m ; i++ ) {
		ar[++k] = getData(0,y[i]-r[i],i);
		ar[++k] = getData(2,y[i]+r[i],i);
	}
	sort(ar+1,ar+k+1,comp);
	for( int i = 1 , cnt = 0 ; i <= k ; i++ ) {
		if(ar[i].type == 0) {
			cnt++;
			open[ar[i].id] = i;
		}
		else if(ar[i].type == 2) {
			cnt--;
			close[ar[i].id] = i;
		}
		sum[0][i] = sum[0][i-1];
		sum[1][i] = sum[1][i-1];
		if(cnt < 2 && ar[i].type == 1)
			sum[cnt][i] += p[ar[i].id];
	}
	for( int i = 1 ; i <= m ; i++ ) {
		int l = open[i];
		int r = close[i];
		LL score = sum[0][k] - (sum[0][r]-sum[0][l-1]) + (sum[1][r]-sum[1][l-1]);
		ans = max(ans,score);
	}
}

int main() {
	input();
	solve();
	printf("%lld\n",ans);
	return 0;
}
