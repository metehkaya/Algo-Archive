#include <bits/stdc++.h>
using namespace std;

int n,s,d;
string ans = "No";

int main() {
	scanf("%d%d%d",&n,&s,&d);
	for( int i = 0 , x,y ; i < n ; i++ ) {
		scanf("%d%d",&x,&y);
		if(x < s && y > d)
			ans = "Yes";
	}
	printf("%s\n",ans.c_str());
	return 0;
}
