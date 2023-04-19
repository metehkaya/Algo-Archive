#include <bits/stdc++.h>
#define maxn 1000001
#define pb push_back
using namespace std;

int n,g;
bool var[maxn];
vector<int> primes[maxn];

int gcd(int x , int y) {
	if(!y)
		return x;
	return gcd(y,x%y);
}

int main() {
	for( int i = 2 ; i < maxn ; i++ )
		if(primes[i].empty())
			for( int j = i ; j < maxn ; j += i )
				primes[j].pb(i);
	scanf("%d",&n);
	bool isCoprime = true;
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		int p = primes[x].size();
		for( int j = 0 ; j < p ; j++ ) {
			int num = primes[x][j];
			if(var[num])
				isCoprime = false;
			else
				var[num] = true;
		}
		if(i == 0)
			g = x;
		else
			g = gcd(g,x);
	}
	if(isCoprime)
		puts("pairwise coprime");
	else if(g == 1)
		puts("setwise coprime");
	else
		puts("not coprime");
	return 0;
}
