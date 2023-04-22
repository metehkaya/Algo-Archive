#include <bits/stdc++.h>
#define maxn 1000003
#define mod 1000000007
using namespace std;

int T,n,k;
int p2[maxn];
char s[maxn];

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	p2[0] = 1;
	for( int i = 1 ; i < maxn ; i++ )
		p2[i] = (p2[i-1] * 2) % mod;
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		int ans = 0;
		scanf("%d%d%s",&n,&k,s);
		for( int i = n-1 , sum = 0 ; i >= 0 ; i-- ) {
			if(s[i] == 'A')
				sum--;
			else
				sum++;
			if(sum > k) {
				sum -= 2;
				ans = (ans + p2[i+1]) % mod;
			}
			if(sum < 0)
				sum = 0;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
