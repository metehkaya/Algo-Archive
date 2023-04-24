#include <bits/stdc++.h>
using namespace std;

const int n = 100;
const int m = 10000;
const int min_rp = 50;
const int min_rq = 40;

int T,p,ans;
string s[n];
int cntp[n];
int cntq[m];
int ones[n];

void reset() {
	memset(cntp,0,sizeof(cntp));
	memset(cntq,0,sizeof(cntq));
}

int main() {
	scanf("%d%d",&T,&p);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		for( int i = 0 ; i < n ; i++ )
			cin >> s[i];
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
				if(s[i][j] == '1')
					cntp[i]++ , cntq[j]++;
		ans = -1;
		for( int i = 0 ; i < n ; i++ )
			if(cntp[i] >= m*min_rp/100) {
				ones[i] = 0;
				for( int j = 0 ; j < m ; j++ )
					if(cntq[j] >= n*min_rq/100)
						if(s[i][j] == '1')
							ones[i]++;
				if(ans == -1 || ones[i] < ones[ans])
					ans = i;
			}
		printf("Case #%d: %d\n",tc,ans+1);
	}
	return 0;
}
