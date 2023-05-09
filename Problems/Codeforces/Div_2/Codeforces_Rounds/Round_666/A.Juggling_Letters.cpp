#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

int T,n;
string ans;
int cnt[26];
string s[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			cin >> s[i];
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < s[i].length() ; j++ )
				cnt[s[i][j]-'a']++;
		ans = "YES";
		for( int i = 0 ; i < 26 ; i++ )
			if(cnt[i]%n)
				ans = "NO";
		cout << ans << endl;
	}
	return 0;
}
