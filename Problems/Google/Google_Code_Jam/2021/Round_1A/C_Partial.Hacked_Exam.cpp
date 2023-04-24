#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

int T,n,m;
LL allcases;
int nsame,ndiff;
LL sumcases[2][2][2];
int score[3];
string str[3];
int tf01[256];
LL dp[41][41];
string strtf = "TF";

LL gcd(LL x , LL y) {
	if(!y)
		return x;
	return gcd(y,x%y);
}

void reset() {
	allcases = 0;
	nsame = ndiff = 0;
	memset(sumcases,0,sizeof(sumcases));
}

void deal(int cc , int ww , int cw , int wc) {
	int nsame = cc + ww;
	int ndiff = cw + wc;
	allcases += dp[nsame][cc] * dp[ndiff][cw];
	if(cc) {
		LL cases = dp[nsame-1][ww] * dp[ndiff][cw];
		sumcases[0][0][0] += cases; // T : TT-00
		sumcases[1][1][1] += cases; // F : FF-11
	}
	if(ww) {
		LL cases = dp[nsame-1][cc] * dp[ndiff][cw];
		sumcases[1][1][0] += cases; // T : FF-11
		sumcases[0][0][1] += cases; // F : TT-00
	}
	if(cw) {
		LL cases = dp[nsame][ww] * dp[ndiff-1][wc];
		sumcases[0][1][0] += cases; // T : TF-01
		sumcases[1][0][1] += cases; // F : TF-10
	}
	if(wc) {
		LL cases = dp[nsame][ww] * dp[ndiff-1][cw];
		sumcases[1][0][0] += cases; // T : FT-10
		sumcases[0][1][1] += cases; // F : TF-01
	}
}

void init() {
	tf01['T'] = 0;
	tf01['F'] = 1;
	for( int i = 0 ; i <= 40 ; i++ )
		dp[i][0] = 1;
	for( int i = 1 ; i <= 40 ; i++ )
		for( int j = 1 ; j <= i ; j++ )
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
}

int main() {
	init();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d",&m,&n);
		for( int i = 0 ; i < m ; i++ )
			cin >> str[i] >> score[i];
		if(m == 1) {
			if(score[0] <= n/2) {
				score[0] = n-score[0];
				for( int i = 0 ; i < n ; i++ )
					if(str[0][i] == 'T')
						str[0][i] = 'F';
					else
						str[0][i] = 'T';
			}
			printf("Case #%d: %s %d/1\n",tc,str[0].c_str(),score[0]);
		}
		else {
			reset();
			for( int i = 0 ; i < n ; i++ ) {
				if(str[0][i] == str[1][i])
					nsame++;
				else
					ndiff++;
			}
			for( int cc = 0 ; cc <= nsame ; cc++ ) {
				int ww = nsame - cc;
				for( int cw = 0 ; cw <= ndiff ; cw++ ) {
					int wc = ndiff - cw;
					if(cc + cw == score[0] && cc + wc == score[1])
						deal(cc,ww,cw,wc);
				}
			}
			LL sump = 0;
			string ans = "";
			for( int i = 0 ; i < n ; i++ ) {
				int a = tf01[str[0][i]];
				int b = tf01[str[1][i]];
				int c = sumcases[a][b][0] >= sumcases[a][b][1] ? 0 : 1;
				ans.pb(strtf[c]);
				sump += sumcases[a][b][c];
			}
			LL g = gcd(sump,allcases);
			sump /= g;
			allcases /= g;
			printf("Case #%d: %s %lld/%lld\n",tc,ans.c_str(),sump,allcases);
		}
	}
	return 0;
}
