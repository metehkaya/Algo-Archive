#include <bits/stdc++.h>
using namespace std;

int T,n;
string str;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> str;
		n = str.length();
		int cntB = 0 , cntD = 0;
		for( int i = 1 ; i < n ; i++ ) {
			if(str[i] == 'B')
				cntB++;
			else if(str[i] == '.')
				cntD++;
		}
		if(cntD >= 1 && cntB >= cntD)
			printf("Case #%d: Y\n",tc);
		else
			printf("Case #%d: N\n",tc);
	}
	return 0;
}
