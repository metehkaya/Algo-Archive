#include <bits/stdc++.h>
using namespace std;

int x,y;

int main() {
	scanf("%d%d",&x,&y);
	if(x > y)
		swap(x,y);
	string ans = (x+3 > y) ? "Yes" : "No";
	cout << ans << endl;
	return 0;
}
