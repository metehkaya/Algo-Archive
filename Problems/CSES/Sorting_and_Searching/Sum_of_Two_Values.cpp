#include <bits/stdc++.h>
using namespace std;

int n,sum;
map<int,int> indexx;

int main() {
	scanf("%d%d",&n,&sum);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		auto it = indexx.find(sum-x);
		if(it != indexx.end()) {
			printf("%d %d\n",it->second,i+1);
			return 0;
		}
		indexx[x] = i+1;
	}
	printf("IMPOSSIBLE\n");
	return 0;
}