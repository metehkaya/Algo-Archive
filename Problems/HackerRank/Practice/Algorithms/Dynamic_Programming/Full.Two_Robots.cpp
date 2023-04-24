#include <bits/stdc++.h>
#define maxn 1001
using namespace std;

int T,n,m;
int a[maxn];
int b[maxn];
int dp[maxn][maxn];

int getLoc(int index, int robot) {
	if(robot == 0)
		return a[index];
	else
		return b[robot];
}

int f(int index, int robot) {
	if(index == m+1)
		return 0;
	if(dp[index][robot] != -1)
		return dp[index][robot];
	int loc1,loc2;
	loc1 = getLoc(index, robot);
	loc2 = getLoc(index, index-1);
	int cost1 = f(index+1, index-1) + abs(loc1-a[index]) + abs(a[index]-b[index]);
	int cost2 = f(index+1, robot) + abs(loc2-a[index]) + abs(a[index]-b[index]);
	return dp[index][robot] = min(cost1, cost2);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&n,&m);
		for( int i = 1 ; i <= m ; i++ )
			scanf("%d%d",&a[i],&b[i]);
		memset(dp, -1, sizeof(dp));
		printf("%d\n",f(1,0));
	}
	return 0;
}
