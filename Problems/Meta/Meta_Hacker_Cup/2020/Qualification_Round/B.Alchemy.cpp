#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> s;
		int a = 0 , b = 0;
		for( int i = 0 ; i < n ; i++ )
			if(s[i] == 'A')
				a++;
			else
				b++;
		char ans = (abs(a-b) == 1) ? 'Y' : 'N';
		printf("Case #%d: %c\n",tc,ans);
	}
	return 0;
}
