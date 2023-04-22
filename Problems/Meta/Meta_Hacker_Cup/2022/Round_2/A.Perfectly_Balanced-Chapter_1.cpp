#include <bits/stdc++.h>
#define maxn 1000003
#define pb push_back
using namespace std;

int T,n,q,ans;
char s[maxn];
int cnt[maxn][26];
vector<int> indices[26];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	ans = 0;
	memset(cnt,0,sizeof(cnt));
	for( int i = 0 ; i < 26 ; i++ )
		indices[i].clear();
}

void input() {
	scanf("%s",s+1);
	n = strlen(s+1);
	scanf("%d",&q);
}

void solve() {
	for( int i = 1 ; i <= n ; i++ ) {
		int c = s[i]-'a';
		indices[c].pb(i);
		for( int j = 0 ; j < 26 ; j++ )
			cnt[i][j] = cnt[i-1][j] + (c==j);
	}
	while(q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		int len = r-l+1;
		if(len % 2 == 0)
			continue;
		vector<int> total(26,0);
		for( int i = 0 ; i < 26 ; i++ )
			total[i] = cnt[r][i] - cnt[l-1][i];
		int odd = -1 , cntodd = 0;
		for( int i = 0 ; i < 26 ; i++ )
			if(total[i] % 2)
				odd = i , cntodd++;
		if(cntodd != 1)
			continue;
		int halflen = len/2;
		int m = l+halflen-1;
		vector<int> halftotal(26,0);
		for( int i = 0 ; i < 26 ; i++ )
			halftotal[i] = cnt[m][i] - cnt[l-1][i];
		vector<int>::iterator it = upper_bound(indices[odd].begin(),indices[odd].end(),m);
		if((*it) <= r) {
			bool ok = true;
			for( int i = 0 ; i < 26 && ok ; i++ )
				if(i == odd && 2*halftotal[i]+1 != total[i])
					ok = false;
				else if(i != odd && 2*halftotal[i] != total[i])
					ok = false;
			if(ok) {
				ans++;
				continue;
			}
		}
		it = lower_bound(indices[odd].begin(),indices[odd].end(),l);
		if((*it) <= m) {
			bool ok = true;
			halftotal[odd]--;
			halftotal[s[m+1]-'a']++;
			total[odd]--;
			for( int i = 0 ; i < 26 && ok ; i++ )
				if(2*halftotal[i] != total[i])
					ok = false;
			if(ok)
				ans++;
		}
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
