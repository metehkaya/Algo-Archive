#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL x,y;
map<LL,LL> dp;

LL f(LL y) {
	if(y <= x)
		return x-y;
	if(dp.count(y))
		return dp[y];
	LL res = y-x;
	if(y%2 == 0)
		res = min(res,f(y/2)+1);
	else
		res = min(res,min(f(y/2),f(y/2+1))+2);
	return dp[y] = res;
}

int main() {
	cin >> x >> y;
	cout << f(y) << endl;
	return 0;
}
