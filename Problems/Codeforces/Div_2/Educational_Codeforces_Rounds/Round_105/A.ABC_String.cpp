#include <bits/stdc++.h>
using namespace std;

int T,n;
int add[3];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		string s;
		cin >> s;
		n = s.length();
		bool ok = false;
		for( int a = -1 ; a <= +1 ; a += 2 )
			for( int b = -1 ; b <= +1 ; b += 2 )
				for( int c = -1 ; c <= +1 ; c += 2 ) {
					add[0] = a;
					add[1] = b;
					add[2] = c;
					int val = 0;
					for( int i = 0 ; i < n ; i++ ) {
						val += add[s[i]-'A'];
						if(val < 0)
							break;
					}
					if(val == 0)
						ok = true;
				}
		if(ok)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
