#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

int T,n,x;
bool isZero[maxn];
string s;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> s >> x;
		n = s.length();
		for( int i = 0 ; i < n ; i++ )
			isZero[i] = false;
		for( int i = 0 ; i < n ; i++ )
			if(s[i] == '0') {
				if(i >= x)
					isZero[i-x] = true;
				if(i+x < n)
					isZero[i+x] = true;
			}
		bool imp = false;
		for( int i = 0 ; i < n ; i++ )
			if(s[i] == '1') {
				int cnt = 0;
				if(i >= x && !isZero[i-x])
					cnt++;
				if(i+x < n && !isZero[i+x])
					cnt++;
				if(cnt == 0)
					imp = true;
			}
		if(imp)
			puts("-1");
		else {
			for( int i = 0 ; i < n ; i++ )
				if(isZero[i])
					printf("0");
				else
					printf("1");
			puts("");
		}
	}
	return 0;
}
