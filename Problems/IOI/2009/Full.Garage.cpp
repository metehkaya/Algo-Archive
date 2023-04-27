#include <bits/stdc++.h>
#define maxn 101
#define maxm 2001
using namespace std;

int n,m,ans;
int r[maxn];
int w[maxm];
int slot[maxm];
bool mark[maxn];
queue<int> Q;

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&r[i]);
	for( int i = 1 ; i <= m ; i++ )
		scanf("%d",&w[i]);
	for( int q = 0 , id ; q < 2*m ; q++ ) {
		scanf("%d",&id);
		if(id > 0) {
			int idx = -1;
			for( int i = 1 ; i <= n ; i++ )
				if(!mark[i]) {
					idx = i;
					slot[id] = i;
					mark[i] = true;
					ans += r[i] * w[id];
					break;
				}
			if(idx == -1)
				Q.push(id);
		}
		else {
			id = -id;
			if(Q.empty())
				mark[slot[id]] = false;
			else {
				int car = Q.front();
				Q.pop();
				ans += r[slot[id]] * w[car];
				slot[car] = slot[id];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
