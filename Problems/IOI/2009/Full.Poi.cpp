#include <bits/stdc++.h>
#define maxn 2001
using namespace std;

struct person {
	int score,cnt,id;
}ar[maxn];

int n,m,p;
int cnt[maxn];
int x[maxn][maxn];

bool comp(const person& a , const person& b) {
	if(a.score != b.score)
		return a.score > b.score;
	if(a.cnt != b.cnt)
		return a.cnt > b.cnt;
	return a.id < b.id;
}

int main() {
	scanf("%d%d%d",&n,&m,&p);
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) {
			scanf("%d",&x[i][j]);
			cnt[j] += x[i][j];
		}
	for( int i = 1 ; i <= n ; i++ ) {
		ar[i].id = i;
		for( int j = 1 ; j <= m ; j++ )
			if(x[i][j])
				ar[i].cnt++ , ar[i].score += n-cnt[j];
	}
	sort(ar+1,ar+n+1,comp);
	for( int i = 1 ; i <= n ; i++ )
		if(ar[i].id == p) {
			printf("%d %d\n",ar[i].score,i);
			break;
		}
	return 0;
}
