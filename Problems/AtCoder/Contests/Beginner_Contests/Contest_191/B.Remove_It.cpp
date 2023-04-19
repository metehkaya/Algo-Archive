#include <bits/stdc++.h>
using namespace std;

int n,x;

int main() {
	scanf("%d%d",&n,&x);
	for( int i = 0 , v ; i < n ; i++ ) {
		scanf("%d",&v);
		if(v != x)
			printf("%d ",v);
	}
	puts("");
	return 0;
}
