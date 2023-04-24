#include <bits/stdc++.h>
#define maxn 100003
using namespace std;

int n,mn,mx,diff;
int cnt[26];
char s[maxn];

int main() {
	scanf("%s",s);
	n = strlen(s);
	for( int i = 0 ; i < n ; i++ )
		cnt[s[i]-'a']++;
	mn = maxn;
	for( int i = 0 ; i < 26 ; i++ )
		if(cnt[i]) {
			diff++;
			mn = min(mn,cnt[i]);
			mx = max(mx,cnt[i]);
		}
	if(mn == mx)
		puts("YES");
	else if(n == (diff-1) * mn + mx && mx == mn + 1)
		puts("YES");
	else if(n == (diff-1) * mx + mn && mn == 1)
		puts("YES");
	else
		puts("NO");
	return 0;
}
