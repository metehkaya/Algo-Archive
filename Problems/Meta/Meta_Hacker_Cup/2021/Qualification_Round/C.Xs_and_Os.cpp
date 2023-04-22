#include <bits/stdc++.h>
using namespace std;

int T,n;
string s[50];
int cntr[50][2];
int cntc[50][2];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	memset(cntr,0,sizeof(cntr));
	memset(cntc,0,sizeof(cntc));
}

void solve(int& ans , int& cnt) {
	for( int i = 0 ; i < n ; i++ )
		if(!cntr[i][1]) {
			int add = n-cntr[i][0];
			if(ans == -1 || add < ans)
				ans = add , cnt = 1;
			else if(ans == add)
				cnt += 1;
		}
	for( int i = 0 ; i < n ; i++ )
		if(!cntc[i][1]) {
			int add = n-cntc[i][0];
			if(ans == -1 || add < ans)
				ans = add , cnt = 1;
			else if(ans == add)
				cnt += 1;
		}
}

int solve2() {
	int res = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < n ; j++ )
			if(s[i][j] == '.') {
				if(!cntr[i][1] && cntr[i][0] == n-1)
					res++;
				else if(!cntc[j][1] && cntc[j][0] == n-1)
					res++;
			}
	return res;
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ ) {
			cin >> s[i];
			for( int j = 0 ; j < n ; j++ )
				if(s[i][j] == 'X')
					cntr[i][0]++,cntc[j][0]++;
				else if(s[i][j] == 'O')
					cntr[i][1]++,cntc[j][1]++;
		}
		int ans = -1 , cnt = 0;
		solve(ans,cnt);
		if(ans == 1)
			cnt = solve2();
		if(ans != -1)
			printf("Case #%d: %d %d\n",tc,ans,cnt);
		else
			printf("Case #%d: Impossible\n",tc);
	}
	return 0;
}
