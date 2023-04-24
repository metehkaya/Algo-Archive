#include <bits/stdc++.h>
#define fi first
#define se second
#define maxw 20003
#define maxs 200003
#define mod1 1000000007LL
#define mod2 1000000009LL
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pi;

int T,n,m;
char w[maxw];
char s[maxs];
int cntw[26];
int cnts[maxs][26];
LL pw1[maxs];
LL pw2[maxs];
map<pi,int> hashh;

void reset() {
	hashh.clear();
	memset(cntw,0,sizeof(cntw));
}

void precalc() {
	pw1[0] = 1;
	for( int i = 1 ; i < maxs ; i++ )
		pw1[i] = (pw1[i-1]*26LL) % mod1;
	pw2[0] = 1;
	for( int i = 1 ; i < maxs ; i++ )
		pw2[i] = (pw2[i-1]*26LL) % mod2;
}

void read() {
	scanf("%s%s",w+1,s+1);
	m = strlen(w+1);
	n = strlen(s+1);
}

bool check(int head) {
	for( int i = 0 ; i < 26 ; i++ )
		if(cnts[head+m-1][i]-cnts[head-1][i] != cntw[i])
			return false;
	return true;
}

bool lexi( int l , int r ) {
	for( int i = 0 ; i < m ; i++ ) {
		if(s[l+i] < s[r+i])
			return true;
		else if(s[l+i] > s[r+i])
			return false;
	}
	return false;
}

void solve() {
	for( int i = 1 ; i <= m ; i++ )
		cntw[w[i]-'a']++;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 0 ; j < 26 ; j++ ) {
			if('a'+j == s[i])
				cnts[i][j] = cnts[i-1][j]+1;
			else
				cnts[i][j] = cnts[i-1][j];
		}
	LL curr1 = 0 , curr2 = 0;
	int res_mx = 0 , res_id = 0;
	for( int i = 1 ; i <= m ; i++ ) {
		curr1 = (curr1*26LL) % mod1;
		curr1 = (curr1+s[i]-'a') % mod1;
		curr2 = (curr2*26LL) % mod2;
		curr2 = (curr2+s[i]-'a') % mod2;
	}
	if(check(1)) {
		res_mx = ++hashh[pi(curr1,curr2)];
		res_id = 1;
	}
	for( int i = 2 ; i <= n-m+1 ; i++ ) {
		LL neg1 = (s[i-1]-'a') * pw1[m-1];
		neg1 %= mod1;
		curr1 = (curr1-neg1+mod1) % mod1;
		curr1 = (curr1*26LL) % mod1;
		curr1 = (curr1+s[i+m-1]-'a') % mod1;
		LL neg2 = (s[i-1]-'a') * pw2[m-1];
		neg2 %= mod2;
		curr2 = (curr2-neg2+mod2) % mod2;
		curr2 = (curr2*26LL) % mod2;
		curr2 = (curr2+s[i+m-1]-'a') % mod2;
		if(check(i)) {
			int val = ++hashh[pi(curr1,curr2)];
			if(val > res_mx) {
				res_mx = val;
				res_id = i;
			}
			else if(val == res_mx && lexi(i,res_id))
				res_id = i;
		}
	}
	if(res_mx) {
		for( int i = res_id ; i < res_id+m ; i++ )
			printf("%c",s[i]);
		puts("");
	}
	else
		puts("-1");
}

int main() {
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		read();
		solve();
	}
	return 0;
}
