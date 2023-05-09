#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> s;
		bool isLeft = true , isRight = true;
		for( int i = 0 ; i < n ; i++ )
			if(s[i] == '>')
				isLeft = false;
			else if(s[i] == '<')
				isRight = false;
		if(isLeft || isRight)
			printf("%d\n",n);
		else {
			int cnt = 0;
			for( int i = 0 ; i < n ; i++ )
				if(s[i] == '-' || s[(i-1+n)%n] == '-')
					cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
}
