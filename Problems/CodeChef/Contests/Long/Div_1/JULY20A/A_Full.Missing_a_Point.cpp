#include <bits/stdc++.h>
using namespace std;

int T,n;
map<int,int> xs,ys;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		xs.clear() , ys.clear();
		for( int i = 1 , x , y ; i < 4*n ; i++ ) {
			scanf("%d%d",&x,&y);
			xs[x]++ , ys[y]++;
		}
		int x,y;
		map<int,int>::iterator it;
		for( it = xs.begin() ; it != xs.end() ; it++ )
			if(it->second % 2) {
				x = it->first;
				break;
			}
		for( it = ys.begin() ; it != ys.end() ; it++ )
			if(it->second % 2) {
				y = it->first;
				break;
			}
		printf("%d %d\n",x,y);
	}
	return 0;
}
