#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,y;
char str[5];

int main() {
	LL x = 0;
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%s%d",str,&y);
		if(str[0] == 'a')
			x = max(x,x+y);
		else
			x = max(x,(LL)y);
	}
	cout << x << endl;
	return 0;
}
