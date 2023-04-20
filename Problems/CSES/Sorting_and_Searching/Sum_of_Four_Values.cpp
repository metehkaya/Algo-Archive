#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 1000
using namespace std;
typedef pair<int,int> pi;

int n,x;
int ar[maxn];
map<int,pi> hashh;

int main() {
	scanf("%d%d",&n,&x);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 2 ; i < n-1 ; i++ ) {
		for( int j = 0 ; j < i-1 ; j++ )
			hashh[ar[j]+ar[i-1]] = pi(j+1,i);
		for( int j = i+1 ; j < n ; j++ ) {
			int rem = x - ar[i] - ar[j];
			auto it = hashh.find(rem);
			if(it != hashh.end()) {
				printf("%d %d %d %d\n",it->se.fi,it->se.se,i+1,j+1);
				return 0;
			}
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}