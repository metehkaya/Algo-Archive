#include <bits/stdc++.h>
using namespace std;

int T,p,x,y;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d",&p,&x,&y);
		bool ans = ( (x-50) * (x-50) + (y-50) * (y-50) ) <= 2500;
		if(x == 50 && y >= 50)
			ans &= (p > 0);		
		else if(x == 50 && y < 50)
			ans &= (p >= 50);
		else if(x < 50 && y == 50)
			ans &= (p >= 75);
		else if(x > 50 && y == 50)
			ans &= (p >= 25);
		else if(x < 50 && y > 50) {
			double r1 = atan( (50.0 - x) / (y - 50.0) );
			double r2 = 100 - r1 / (M_PI / 2.0) * 25;
			ans &= (p >= r2);
		}
		else if(x > 50 && y > 50) {
			double r1 = atan( (x - 50.0) / (y - 50.0) );
			double r2 = 0 + r1 / (M_PI / 2.0) * 25;
			ans &= (p >= r2);
		}
		else if(x > 50 && y < 50) {
			double r1 = atan( (50.0 - y) / (x - 50.0) );
			double r2 = 25 + r1 / (M_PI / 2.0) * 25;
			ans &= (p >= r2);
		}
		else {
			double r1 = atan( (50.0 - y) / (50.0 - x) );
			double r2 = 75 - r1 / (M_PI / 2.0) * 25;
			ans &= (p >= r2);
		}
		string s = ans ? "black" : "white";
		printf("Case #%d: %s\n",tc,s.c_str());
	}
	return 0;
}

