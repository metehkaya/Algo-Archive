#include <bits/stdc++.h>
#define maxn 1003
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int T,n,m;
char s[maxn];
char t[maxn];
bool mark[maxn][maxn];

void f(int i , int j) {
	if(mark[i][j])
		return;
	mark[i][j] = true;
	if(j == m) {
		if(i == n || s[i] <= 'Z')
			return;
		f(i+1,j);
		return;
	}
	if(i == n)
		return;
	if(s[i] <= 'Z') {
		if(s[i] == t[j])
			f(i+1,j+1);
	}
	else {
		f(i+1,j);
		if(s[i] == t[j] + 'a' - 'A')
			f(i+1,j+1);
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s%s",s,t);
		n = strlen(s);
		m = strlen(t);
		memset(mark,0,sizeof(mark));
		f(0,0);
		if(mark[n][m])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
