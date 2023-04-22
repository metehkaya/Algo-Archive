#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;
int d[26][26];
bool isvowel[26];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void init() {
	isvowel['A'-'A'] = true;
	isvowel['E'-'A'] = true;
	isvowel['I'-'A'] = true;
	isvowel['O'-'A'] = true;
	isvowel['U'-'A'] = true;
	for( int i = 0 ; i < 26 ; i++ )
		for( int j = 0 ; j < 26 ; j++ )
			if(i != j)
				d[i][j] = (isvowel[i] == isvowel[j]) + 1;
}

int solve() {
	int ans = INT_MAX;
	for( int c = 0 ; c < 26 ; c++ ) {
		int sum = 0;
		for( int i = 0 ; i < n ; i++ ) {
			int k = s[i]-'A';
			sum += d[c][k];
		}
		ans = min(ans,sum);
	}
	return ans;
}

int main() {
	io();
	init();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> s;
		n = s.length();
		int ans = solve();
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
