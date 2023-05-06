#include <bits/stdc++.h>
using namespace std;

int T,n,m;
int cntEO[2];

int getBit1(int val) {
	int cnt = 0;
	while(val) {
		cnt++;
		val -= (val & (-val));
	}
	return cnt;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cntEO[0] = cntEO[1] = 0;
		scanf("%d%d",&n,&m);
		for( int i = 0 ; i < n ; i++ ) {
			int val;
			scanf("%d",&val);
			cntEO[getBit1(val)%2]++;
		}
		for( int i = 0 ; i < m ; i++ ) {
			int val;
			scanf("%d",&val);
			if(getBit1(val) % 2 == 0)
				printf("%d %d\n",cntEO[0],cntEO[1]);
			else
				printf("%d %d\n",cntEO[1],cntEO[0]);
		}
	}
	return 0;
}
