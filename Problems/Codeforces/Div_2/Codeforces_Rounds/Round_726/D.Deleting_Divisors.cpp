#include <bits/stdc++.h>
using namespace std;

int T,n;

bool check(int n) {
	for( int i = 1 ; i <= 29 ; i += 2 )
		if(n == (1<<i))
			return false;
	return (n%2) == 0;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		if(check(n))
			puts("Alice");
		else
			puts("Bob");
	}
	return 0;
}
