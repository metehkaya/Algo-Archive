#include <bits/stdc++.h>
#define maxn 100001
#define pb push_back
using namespace std;

const int P = 5;

int n,k,ans;
bool var[maxn];

int gcd(int a, int b) {
	if(!b)
		return a;
	return gcd(b, a%b);
}

int main() {
	scanf("%d%d",&n,&k);
	for( int i = 1 , x ; i <= n ; i++ ) {
		scanf("%d",&x);
		var[x] = true;
	}
	for( int i = 1 ; i < maxn ; i++ ) {
		vector<int> v;
		bool ok = var[i];
		if(!ok) {
			for( int j = 2*i ; j < maxn ; j += i )
				if(var[j])
					v.pb(j/i);
			if( v.size() > 0 ) {
				int kk = min(k, (int) v.size());
				for( int p = 1 ; p <= P && !ok ; p++ ) {
					random_shuffle(v.begin(), v.end());
					int g = v[0];
					for( int l = 1 ; g > 1 && l < kk ; l++ )
						g = gcd( g , v[l] );
					ok = (g == 1);
				}
			}
		}
		if(ok)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
