#include <bits/stdc++.h>
using namespace std;

int x,y,n;
int mn,mx;

int main() {
	scanf("%d%d%d",&x,&y,&n);
	mn = abs(x-n);
	if(n <= y)
		mx = x+n;
	else
		mx = x+y-(n-y);
	printf("%d %d\n",mn,mx);
	return 0;
}
