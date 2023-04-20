#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s;

int main() {
	scanf("%d",&n);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		s.insert(x);
	}
	printf("%d\n",s.size());
	return 0;
}