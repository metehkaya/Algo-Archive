#include <bits/stdc++.h>
#define maxn 300001
#define pb push_back
using namespace std;

int n,cX,cY;
bool markX[maxn];
bool markY[maxn];
vector<int> vX,vY;

void read() {
	scanf("%d",&n);
	for( int i = 0 , x1 , y1 , x2 , y2 ; i < n ; i++ ) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for( int x = x1 ; x <= x2 ; x++ )
			markX[x] = true;
		for( int y = y1 ; y <= y2 ; y++ )
			markY[y] = true;
	}
}

void solve() {
	for( int i = 0 ; i < maxn ; i++ )
		if(markX[i])
			cX++;
	for( int i = 0 ; i < maxn ; i++ )
		if(markY[i])
			cY++;
	if(cX < cY) {
		cY = 0;
		for( int i = 0 ; i < maxn ; i++ )
			if(markX[i])
				vX.pb(i);
	}
	else {
		cX = 0;
		for( int i = 0 ; i < maxn ; i++ )
			if(markY[i])
				vY.pb(i);
	}
}

void output() {
	printf("%d\n",cX+cY);
	printf("%d\n",cX);
	for( int i = 0 ; i < cX ; i++ )
		printf("%d ",vX[i]);
	puts("");
	printf("%d\n",cY);
	for( int i = 0 ; i < cY ; i++ )
		printf("%d ",vY[i]);
	puts("");
}

int main() {
	read();
	solve();
	output();
	return 0;
}
