#include <bits/stdc++.h>
#define maxn 1003
using namespace std;

int T,n,m;
int val[256];
int st[maxn];
char str[maxn];

int main() {
	val['('] = 1 , val['['] = 2 , val['{'] = 3;
	val[')'] = 4 , val[']'] = 5 , val['}'] = 6;
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s",str+1);
		m = strlen(str+1);
		n = 0;
		string ans = "YES";
		for( int i = 1 ; i <= m && ans == "YES" ; i++ ) {
			int value = val[str[i]];
			if(value <= 3)
				st[++n] = value;
			else if(!n)
				ans = "NO";
			else if(st[n] != value-3)
				ans = "NO";
			else
				n--;
		}
		if(n > 0)
			ans = "NO";
		cout << ans << endl;
	}
	return 0;
}
