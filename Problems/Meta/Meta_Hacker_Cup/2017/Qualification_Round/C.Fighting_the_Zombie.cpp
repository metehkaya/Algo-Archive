#include <bits/stdc++.h>
#define maxm 402
using namespace std;

int T,n,m;
double dp[maxm];
double add[maxm];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&m,&n);
		double ans = 0;
		for( int q = 0 ; q < n ; q++ ) {
			int x=0 , y=0 , z=0;
			string str;
			cin >> str;
			int len = str.length();
			int idx = 0;
			while(str[idx] != 'd') {
				x *= 10;
				x += str[idx] - '0';
				idx++;
			}
			idx++;
			while(idx < len && str[idx] != '+' && str[idx] != '-') {
				y *= 10;
				y += str[idx] - '0';
				idx++;
			}
			if(idx < len) {
				int mult = (str[idx] == '+') ? 1 : -1;
				idx++;
				while(idx < len) {
					z *= 10;
					z += str[idx] - '0';
					idx++;
				}
				z *= mult;
			}
			int req = max(m-z,0);
			memset(dp,0,sizeof(dp));
			dp[0] = 1;
			double p = 1.0 / y;
			for( int i = 0 ; i < x ; i++ ) {
				memset(add,0,sizeof(add));
				for( int j = 0 ; j <= i*y ; j++ )
					add[j+1] += dp[j]*p , add[j+1+y] -= dp[j]*p;
				memset(dp,0,sizeof(dp));
				dp[0] = add[0];
				for( int j = 1 ; j <= (i+1)*y ; j++ )
					dp[j] = dp[j-1] + add[j];
			}
			double sum = 0;
			for( int i = req ; i <= x*y ; i++ )
				sum += dp[i];
			ans = max(ans,sum);
		}
		printf("Case #%d: %lf\n",tc,ans);
	}
	return 0;
}
