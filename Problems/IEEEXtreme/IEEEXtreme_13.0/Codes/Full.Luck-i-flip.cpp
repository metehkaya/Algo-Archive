#include <bits/stdc++.h>
#define maxn 22
#define maxb 101
#define maxv (1<<maxn)
using namespace std;

int n,b,ans;
int cnt[maxb];
int dist[maxv];
int mark[maxv];
char str[maxb][maxn+3];

void bfs() {
	queue<int> Q;
	n = strlen(str[1]);
	for( int i = 1 ; i <= b ; i++ ) {
		int value = 0;
		for( int j = 0 ; j < n ; j++ )
			value += (str[i][j] - '0') * (1 << (n-1-j));
		if( dist[value] == 0 ) {
			Q.push(value);
			mark[value] = i;
			dist[value] = 1;
		}
		else if( mark[value] > 0 )
			mark[value] = -1;
	}
	while(!Q.empty()) {
		int value = Q.front();
		Q.pop();
		if( mark[value] != -1 )
			cnt[mark[value]]++;
		if( dist[value] == 4 )
			continue;
		for( int i = 0 ; i < n ; i++ ) {
			int tmp = (value ^ (1<<i));
			if( dist[tmp] == 0 ) {
				Q.push(tmp);
				mark[tmp] = mark[value];
				dist[tmp] = dist[value] + 1;
			}
			else if( dist[tmp] == dist[value] + 1 && mark[value] != mark[tmp] )
				mark[tmp] = -1;
		}
	}
}

int main() {
	scanf("%d",&b);
	for( int i = 1 ; i <= b ; i++ )
		scanf("%s",str[i]);
	bfs();
	ans = maxv;
	for( int i = 1 ; i <= b ; i++ )
		ans = min(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}
