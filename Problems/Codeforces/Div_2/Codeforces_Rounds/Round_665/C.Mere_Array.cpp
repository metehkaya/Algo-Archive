#include <bits/stdc++.h>
#define maxn 100000
#define pb push_back
using namespace std;

int T,n;
int a[maxn];
int b[maxn];

int gcd(int x , int y) {
	if(!y)
		return x;
	return gcd(y,x%y);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d",&a[i]);
			b[i] = a[i];
		}
		sort(b,b+n);
		string ans = "YES";
		for( int i = 0 ; i < n ; i++ ) {
			int cnt = 0;
			if(a[i]%b[0] == 0)
				cnt++;
			if(b[i]%b[0] == 0)
				cnt++;
			if(cnt == 1)
				ans = "NO";
			else if(cnt == 0 && a[i] != b[i])
				ans = "NO";
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}
