#include <bits/stdc++.h>
#define maxb (18)
#define maxn (1<<maxb)
using namespace std;

string s,e;
int T,S,E,ans;
int dist[maxn];

void reset() {
	memset(dist,-1,sizeof(dist));
}

void output(int tc) {
	if(ans == -1)
		printf("Case #%d: IMPOSSIBLE\n",tc);
	else
		printf("Case #%d: %d\n",tc,ans);
}

void input() {
	cin >> s >> e;
	S = 0;
	int lens = s.length();
	for( int i = 0 ; i < lens ; i++ )
		S = 2*S + (s[i]=='1');
	E = 0;
	int lene = e.length();
	for( int i = 0 ; i < lene ; i++ )
		E = 2*E + (e[i]=='1');
}

int solve() {
	queue<int> Q;
	Q.push(S);
	dist[S] = 0;
	while(!Q.empty()) {
		int x = Q.front();
		int d = dist[x];
		Q.pop();
		if(x == E)
			return d;
		if(2*x < maxn)
			if(dist[2*x] == -1) {
				Q.push(2*x);
				dist[2*x] = d+1;
			}
		int num = 0;
		bool seen1 = false;
		bool seen0 = false;
		for( int i = maxb-1 ; i >= 0 ; i-- ) {
			int dig = ( (x & (1<<i)) > 0 );
			int dig2 = 1-dig;
			if(seen1 && !seen0) {
				if(dig == 0)
					seen0 = true;
			}
			else if(!seen1 && !seen0) {
				if(dig == 1)
					seen1 = true;
			}
			if(seen0)
				num += (dig2 << i);
		}
		if(!seen1)
			num = 1;
		else if(!seen0)
			num = 0;
		if(dist[num] == -1) {
			Q.push(num);
			dist[num] = d+1;
		}
	}
	return -1;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		ans = solve();
		output(tc);
	}
	return 0;
}
